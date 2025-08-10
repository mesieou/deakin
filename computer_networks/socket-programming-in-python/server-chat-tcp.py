from socket import *
serverPort = 11500
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('',serverPort))
serverSocket.listen(1)
print("The Server is listening")
while True:
    connectionSocket, addr = serverSocket.accept()
    message = connectionSocket.recv(2048).decode()
    ClientSendMessage1 = str(len(message)) +  " characters received\n"
    ClientSendMessage2 = message.upper()
    response = ClientSendMessage1 + ClientSendMessage2
    connectionSocket.send(response.encode())
    
    connectionSocket.close()

