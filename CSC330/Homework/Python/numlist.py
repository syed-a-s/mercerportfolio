# Print prime numbers up to a specific value

def isPrime(n) : 
      
      prime = True 
      
      for i in range(2, n) :
            if n % i == 0 :
                  prime = False
                  break
      
      return prime
      
def printPrime() :

      n = input("Enter a number: ")
      
      print("All numbers prime numbers from 1 to", n, "are: ")
      
      for i in range(1, int(n)) :
            if isPrime(i) :
                  print(i)
      
printPrime()