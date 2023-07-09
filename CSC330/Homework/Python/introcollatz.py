#!/usr/bin/python3

i = input("Choose a number : ")
counter = 0
while i != 1:
    print(int(i))
    if ( i % 2  == 0 ):
        i = i / 2
    else:
        i = i * 3 + 1
    counter += 1

print(int(i))  
print("Num of Iteration(s): ", counter)