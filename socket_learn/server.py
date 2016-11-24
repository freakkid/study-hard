# server.py
import socket


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(('localhost', 8001))
sock.listen(1)
while True:
    connection, address = sock.accept()
    try:
        connection.settimeout(5)
        buf = connection.recv(1024)
        if buf == '1':
            connection.send('hello')
        else:
            connection.send('bye')
    except socket.timeout:
        print 'time out'
    connection.close()

