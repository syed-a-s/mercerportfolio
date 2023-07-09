# Iterative Method to Compute Factorial
import sys

def fact(val) : 
      if(val < 0) :
            return "--NO--\n"
      elif(val == 0) or (val == 1) :
            return 1
      else :
            factVal = 1
            for i in range(val, 1, -1) : 
                  factVal = factVal * i
            return factVal
            
# Take command line input, compute the factorial, print it out            
userInput = int(sys.argv[1])
print("Factorial of " + str(userInput) + " : " + str(fact(userInput)))