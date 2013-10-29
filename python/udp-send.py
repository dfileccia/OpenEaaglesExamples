#!/usr/bin/python
#
# UDP send
#
import socket

#UDP_IP = "127.0.0.1"
UDP_IP = "54.204.9.175"

UDP_PORT = 3000
MESSAGE = "Hello, World!"

print "UDP target IP:", UDP_IP
print "UDP target port:", UDP_PORT
print "message:", MESSAGE

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP

sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))


