# Echo cliet program
import socket


HOST = 'daring.cwi.nl'
PORT = 50007
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
s.sendall('Hello')
data = s.recv(1024)
s.close()
print 'Received', repr(data)

