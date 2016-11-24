#!/usr/bin/python
import socket
HOST=''
PORT=50007
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)     
s.connect((HOST,PORT))      
while 1:
    
    try:
       cmd=raw_input("Please input cmd:")
       s.sendall(cmd)    
       data=s.recv(1024)
       print data
    except KeyboardInterrupt:
       break

s.close()  
