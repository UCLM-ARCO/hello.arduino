#!/usr/bin/python -u
# -*- mode: python; coding: utf-8 -*-

import sys
import Ice

Ice.loadSlice("example.ice")
import Example


class HelloI(Example.Hello):
    def sayHello(self, current):
        print "Hello world!"


class Server(Ice.Application):
    def run(self, args):
        ic = self.communicator()

        device = "/dev/ttyUSB0"
        if len(args) > 1:
            device = args[1]

        adapter = ic.createObjectAdapterWithEndpoints(
            "Adapter", "serial -d " + device)
        adapter.activate()

        oid = ic.stringToIdentity("Server")
        proxy = adapter.add(HelloI(), oid)
        proxy = proxy.ice_datagram()
        proxy = proxy.ice_encodingVersion(Ice.Encoding_1_0)

        print "Proxy ready: '{0}'".format(proxy)
        self.shutdownOnInterrupt()
        ic.waitForShutdown()


if __name__ == '__main__':
    Server().main(sys.argv, "config")
