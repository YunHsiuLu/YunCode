# -*- coding: utf-8 -*-
import socket
import keyboard
HOST = ''
PORT = 8000

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(10)
while True:
	conn, addr = server.accept()
	clientMessage = str(conn.recv(1024), encoding='utf-8')
	print('Client:', clientMessage)
	serverMessage = 'hi there!'
	conn.sendall(serverMessage.encode())
	conn.close()
