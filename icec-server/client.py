#!/usr/bin/python -u
# -*- mode: python; coding: utf-8 -*-

import sys
import Ice

Ice.loadSlice("example.ice")
import Example


class Client(Ice.Application):
    def run(self, args):
        ic = self.communicator()

        if len(args) != 2:
            print "Usage: {} <proxy>".format(args[0])
            return 1

        proxy = ic.stringToProxy(args[1])
        proxy = Example.HelloPrx.uncheckedCast(proxy)
        proxy = proxy.ice_encodingVersion(Ice.Encoding_1_0)
        proxy.sayHello()

        print "Hello said, client goes to sleep."
        # import time
        # time.sleep(100)

if __name__ == '__main__':
    Client().main(sys.argv, "config")
    print "OK"
