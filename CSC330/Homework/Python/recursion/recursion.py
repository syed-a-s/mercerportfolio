# Recursive Method to Compute Factorial
import sys

def fact(val) :
      if(val < 0) :
            return "--NO--\n"
      elif(val == 0) or (val == 1) :
            return 1
      else : 
            return val * fact(val - 1)
            
# Take command line input, compute the factorial, print it out            
userInput = int(sys.argv[1])
print("Factorial of " + str(userInput) + " : " + str(fact(userInput)))