import socket
import sys

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host =  "10.0.0.178"
port = 9998
s.connect((host, port))
msg = s.recv(1024)
s.close()
print (msg.decode('utf-8'))