# -*- coding: utf-8 -*-
import socket
import keyboard
HOST = '127.0.0.1'
PORT = 8000

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(10)

while True:
	if keyboard.is_pressed('q'):
		print('quit!')
		break
	else:
		conn, addr = server.accept()
		clientMessage = str(conn.recv(1024), encoding='utf-8')
		serverMessage = 'What can I help you?'
		print('Client message is:', clientMessage)
		if clientMessage == '!quit':
			serverMessage = 'Bye!'
		conn.sendall(serverMessage.encode())
		conn.close()
