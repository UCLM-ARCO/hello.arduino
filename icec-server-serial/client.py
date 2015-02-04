#!/usr/bin/python -u
# -*- mode: python; coding: utf-8 -*-

import sys
import Ice

Ice.loadSlice("example.ice")
import Example


class Client(Ice.Application):
    def run(self, args):
        ic = self.communicator()

        str_prx = "Server -d:serial -d /dev/ttyUSB0"
        proxy = ic.stringToProxy(str_prx)
        proxy = Example.HelloPrx.uncheckedCast(proxy)
        proxy = proxy.ice_encodingVersion(Ice.Encoding_1_0)
        proxy.sayHello()

        print "Hello said, client goes to sleep."

if __name__ == '__main__':
    Client().main(sys.argv, "config")
    print "OK"
