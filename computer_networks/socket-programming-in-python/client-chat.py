from socket import *

serverName = 'localhost'  # or IP address of server
serverPort = 11500
clientSocket = socket(AF_INET, SOCK_DGRAM)

# Step 1: send "Hello" to server
clientSocket.sendto("Hello".encode(), (serverName, serverPort))

# Step 2: receive "Hello, What’s your name?"
response, serverAddress = clientSocket.recvfrom(2048)
print(f"From server: {response.decode()}")

# Step 3: input name from terminal
name = input("Enter your name: ")

# Step 4: send name to server
clientSocket.sendto(name.encode(), (serverName, serverPort))

# Step 5: receive welcome message
response, serverAddress = clientSocket.recvfrom(2048)
print(f"From server: {response.decode()}")

clientSocket.close()
