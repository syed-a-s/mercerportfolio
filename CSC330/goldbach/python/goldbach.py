# Goldbach Weak Conjecture
import math

# Stores all prime numbers from 1 to user input
def StorePrime(n) :
      primeNums = []
      for i in range(n) :
            if IsPrime(i) :
                  primeNums.append(i)
      return primeNums
      
# Checks if the given number is prime
def IsPrime(n) : 
      prime = True 
      for i in range(2, n) :
            if n % i == 0 :
                  prime = False
                  break
      return prime

# Finds the triple sum with the lowest norm
def FindMinTriplet(primeNums, userInput) :
      l, r = int, int 
      norm = float('inf')
      triplet = [None] * 3
        
      for i in range(len(primeNums) - 2) :
            l = i + 1
            r = len(primeNums) - 1
            while (l < r) : 
                  if primeNums[i] + primeNums[l] + primeNums[r] == userInput : 
                        if NormOf(primeNums[i], primeNums[l], primeNums[r]) <= norm : 
                              norm = NormOf(primeNums[i], primeNums[l], primeNums[r])
                              triplet[0] = primeNums[i]
                              triplet[1] = primeNums[l]
                              triplet[2] = primeNums[r]
                        l+=1
                        r-=1
                  elif primeNums[i] + primeNums[l] + primeNums[r] < userInput : 
                        l+=1                 
                  else : 
                        r-=1
                        
      print(userInput, ":", "(", triplet[0], ",", triplet[1], ",", triplet[2], ")")

# Find the norm of 3 given numbers
def NormOf(i, j, k) :
      norm = math.sqrt((i*i) + (j*j) + (k*k))
      return norm

# Main function
userInput = int(input("Enter an odd number greater than 7 : "))

if userInput > 7 and userInput % 2 == 1 :
      primeNums = StorePrime(userInput)
      FindMinTriplet(primeNums, userInput)
else :
      print("Please enter a number that is ODD and greater than 7!")
