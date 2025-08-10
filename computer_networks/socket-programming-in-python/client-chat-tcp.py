from socket import *
serverName = "127.0.0.1"
serverPort = 11500
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
message = "Hello SIT202"
clientSocket.send(message.encode())
ServerReply = clientSocket.recv(2048)
print(ServerReply.decode())
clientSocket.close()