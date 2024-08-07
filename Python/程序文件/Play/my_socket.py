import socket
import sys

serversocket = socket. socket(socket.AF_INET, socket. SOCK_STREAM)
host = '10.0.0.239'
port = 40012

serversocket.bind((host, port))
serversocket.listen(5)
while True:
    clientsocket,addr = serversocket.accept()
    print("连接地址:%s"% str(addr))
    msg='hello CyberDog!'+ "\r\n"
    clientsocket.send(msg.encode())
    clientsocket.close()