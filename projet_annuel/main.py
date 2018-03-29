#! /usr/bin/env python
#coding: utf-8

from crawler import testing_module_crawl
from misc import testing_module_msc
from audiorecognition import testing_module_audiorecognition

def main():
    print "That's a main"
    testing_module_msc.testing()
    testing_module_crawl.testing()
    testing_module_audiorecognition.testing()


if __name__ == "__main__":
    main()
