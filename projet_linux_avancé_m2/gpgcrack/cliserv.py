#! /usr/bin/env python
#coding: utf-8

import os
import sys
from scapy.all import *
from netfilterqueue import NetfilterQueue
import logging
from subprocess import *
import multiprocessing
import time

def handle_packet(packet):
    pkt = IP(packet.get_payload())
    if pkt.haslayer(Raw):
        if pkt.haslayer(UDP):
            dport = pkt[UDP].dport
            sport = pkt[UDP].sport
            host = pkt[IP].src
            load = pkt[Raw].load.decode()

            log = ""
            if ':' in load:
                test1 = load.split(':')[0]
                test2 = load.split(':')[1]
                print(test1,test2)
                log = "host={} test1={} test2={}".format(host, test1, test2)
        else:
            log="BAD DATA"

        print(log)

        logging.info(log)
    packet.accept()


def main():

    print("[*] Setting IPTables to watch input packets in NFQUEUE...")
    os.system("iptables -A INPUT -p udp -j NFQUEUE --queue-num 0")
    nfqueue = NetfilterQueue()
    nfqueue.bind(0, handle_packet)
    logging.basicConfig(level=logging.INFO, filename='hashscli.log', format='%(asctime)s %(message)s')
    try:
        print("[*] Waiting for hash packets ...")
        print("[*] Hash founder awaiting...")
        nfqueue.run()
    except KeyboardInterrupt:
        os.system('iptables -F')
        os.system('iptables -X')
        print("[*] IPTables cleaned!")
        pass

if __name__ == "__main__":
    main()

