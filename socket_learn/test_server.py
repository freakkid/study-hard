#!/usr/bin/python
import socket   
import commands
import os


HOST=''
PORT=50007
s= socket.socket(socket.AF_INET,socket.SOCK_STREAM)   
s.bind((HOST,PORT))  
s.listen(1)        

conn, addr=s.accept()  
print'Connected by',addr
os.system('python test_part3_view.py')
print 'test end'
conn.close()
