import socket

HOST = ''
PORT = 8000
flag = False
Name = str(input("Login name: "))
NameMessage = "Name:%s" % (Name)
while True:
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((HOST, PORT))
    clientMessage = str(input())
    client.sendall(clientMessage.encode())
    serverMessage = str(client.recv(1024), encoding='utf-8')
    print('Server:', serverMessage)
    client.close()
    if flag:
        break