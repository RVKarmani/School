#! /usr/bin/env python
#coding: utf-8


import os
import subprocess
from scapy.all import *
from netfilterqueue import NetfilterQueue
import logging

def print_red(prt): print("\033[91m {}\033[00m" .format(prt))
def print_green(prt): print("\033[92m {}\033[00m" .format(prt))

def handle_packet(packet):
    pkt = IP(packet.get_payload())
    if pkt.haslayer(Raw):
        if pkt.haslayer(UDP):
            dport = pkt[UDP].dport
            sport = pkt[UDP].sport
            host = pkt[IP].src
            load = pkt[Raw].load
            
            log = ""
            if ':' in load:
                filename = load.split(':')[0]
                password = load.split(':')[1]
                log = "host={} filename={} password={}".format(host, filename, password)

                if password == filename[::-1]:
                    log = log + " result=OK"
                    send(IP(src=host,dst=host)/UDP(sport=12345,dport=33333)/Raw(load="OK"))
                else:
                    log = log + " result=KO"
                    send(IP(src=host,dst=host)/UDP(sport=12345,dport=33333)/Raw(load="KO"))

            else:
                log = "host={} malformed=true".format(host)
                send(IP(src=host,dst=host)/UDP(sport=12345,dport=33333)/Raw(load="Request should look like this => \nFILENAME:PASSWORD\n\nResult is OK is password match, else KO..."))

            print(log)

            logging.info(log)

    packet.accept()


def main():
    print("[*] Setting IPTables to watch input packets in NFQUEUE...")
    os.system("iptables -A POSTROUTING -p udp --dport 3333 -j NFQUEUE --queue-num 0")

    nfqueue = NetfilterQueue()
    nfqueue.bind(0, handle_packet)
    logging.basicConfig(level=logging.INFO, filename='hashs.log', format='%(asctime)s %(message)s')

    try:
        print("[*] Waiting for packets hash...")
        print("[*] Hashgetter awaiting...")
        nfqueue.run()
    except KeyboardInterrupt:
        os.system('iptables -F')
        os.system('iptables -X')
        print("[*] IPTables cleaned!")
        pass

if __name__ == "__main__":
    main()
