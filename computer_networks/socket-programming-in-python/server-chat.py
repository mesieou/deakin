from socket import *
serverPort = 11500
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('',serverPort))
print("The Server is listening")
while True:
    message, clientAddress = serverSocket.recvfrom(2048)
    ClientSendMessage1 = str(message) +  "is received"
    serverSocket.sendto(ClientSendMessage1.encode(), clientAddress)