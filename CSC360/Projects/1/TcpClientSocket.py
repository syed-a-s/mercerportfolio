from socket import *

def PrintServerMsg(serverMsg):
    print('From Server : ')
    for string in serverMsg:
        print(string)

def main():
    serverName = '127.0.0.1'
    serverPort = 12010
    clientSocket = socket(AF_INET, SOCK_STREAM)
    clientSocket.connect((serverName,serverPort))

    # first : sending the name of the user 
    clientName = input('Input your name here : ')
    clientSocket.send(clientName.encode())
    print()

    # second : receiving serverMessage of the game 
    serverMsg = (clientSocket.recv(1024).decode()).split('|')
    PrintServerMsg(serverMsg)
    
    # the game loop --> runs at the same time as the server
    while 1:
        # third : send guess 
        guess = input('Input guess here : ')
        clientSocket.send(guess.encode())
        
        # fourth : receiving feedback 
        feedback = clientSocket.recv(1024).decode()
        if feedback == 'quit':
            break
        print(feedback)
        
    clientSocket.close()
    
main()