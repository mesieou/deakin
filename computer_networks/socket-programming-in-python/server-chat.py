from socket import *

serverPort = 11500
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print("The Server is listening")

while True:
    message, clientAddress = serverSocket.recvfrom(2048)
    message = message.decode()
    print(f"Received from client: {message}")

    if message == "Hello":
        response = "Hello, What’s your name?"
        serverSocket.sendto(response.encode(), clientAddress)

    else:
        # Here the message should be the client's name
        name = message
        response = f"Hello {name}, Welcome to SIT202"
        serverSocket.sendto(response.encode(), clientAddress)
