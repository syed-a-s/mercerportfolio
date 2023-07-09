from socket import *
import random

def main():
    serverPort = 29132
    serverSocket = socket(AF_INET,SOCK_STREAM)
    serverSocket.bind(('',serverPort))
    serverSocket.listen(1)

    minNum = 1
    maxNum = 100
    attempts = 0
    luckyNum = random.randrange(minNum, maxNum)
    feedback = ''
    serverMessage = "Syed's Lucky Numbers|Number Range : ("+str(minNum)+","+str(maxNum)+")|Please make a guess"
    
    print ("Syed's Lucky Numbers is ready to receive")

    while 1:
        connectionSocket, addr = serverSocket.accept()
    
        # first : receiving name of the user 
        clientName = connectionSocket.recv(1024).decode()
        print(clientName, 'is connected...')
    
        # second : sending the serverMessage of the game 
        connectionSocket.send(serverMessage.encode())
        
        # the game loop --> runs at the same time as the client
        while 1:
            # third : receiving guess 
            guess = (connectionSocket.recv(1024).decode()).lower()
            print('     ', guess)
            
            if guess == 'quit':
                attempts = 0
                feedback = 'quit'
                connectionSocket.send(feedback.encode())
                break
            
            if not guess.isnumeric():
                attempts = attempts + 1
                feedback = "Not a number"
                connectionSocket.send(feedback.encode())
                continue
            number = int(guess)

            if number == luckyNum:
                attempts = attempts + 1
                feedback = 'Correct! It took you '  + str(attempts) + ' attempts. Play again or type "quit" to quit.'
                attempts = 0
                luckyNum = random.randrange(minNum, maxNum)
            elif number > luckyNum:
                attempts = attempts + 1
                feedback = 'Number is too big'
            elif number < luckyNum:
                attempts = attempts + 1
                feedback = 'Number is too small'
            
            # fourth : sending feedback
            connectionSocket.send(feedback.encode())
        
        connectionSocket.close()
        
main()
