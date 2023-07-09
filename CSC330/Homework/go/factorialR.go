package main

import "fmt"
import "os"
import "strconv"

func fact(n int) int {
    if ( n < 0 ) {
        return -1 
    } else if ( n == 0 || n == 1 ) {
        return 1
    } else {
        return n * fact(n-1) 
    }
}

func main() {
    n, err := strconv.Atoi(os.Args[1]) 
    if ( err == nil ) { 
        fmt.Println("The factorial of ", n, " is ", fact(n))
    }   
}