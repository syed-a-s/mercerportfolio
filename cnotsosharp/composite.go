//Zaina Khutliwala Combining All The Functions Together

//Using Zaina's Readin Command Line Arguments Code

package main
import (
	"fmt"
	"os"
	"strconv"
)
 
func main() {

	var value1 string //to store command line argument1
	var value2 string //to store command line argument 2

 	var totalSum int64 = 0 //stores the total sum
  	var count int = 0 //stores the count
	var numHold int64 = 0 //holds the factor
	var currentNum int64 = 0 //current integer

	value1 = os.Args[1] //set the variable to the first command line argument passed by the user
	value2 = os.Args[2] //set the variable to the second command line argument passed by the user


	num1, _ := strconv.ParseInt(value1,10,64) //convert string to integer 64
	num2, _ := strconv.ParseInt(value2,10,64) //convert string to integer 64
	


	currentNum = num1 //set current number to the first number


	//do while loop



	for {


	//if it is not prime 

		if(! isPrime(currentNum)) {
			numHold = factor(currentNum)
			totalSum = totalSum + numHold

  //if it does not equal zero
		 if(numHold != 0) {

			count = count + 1

		}

		}
			currentNum = currentNum + 1

		//condition to stop

		if(currentNum > num2) {

			break


		}

	}


	fmt.Print("Count: ")
	fmt.Println(count)
	fmt.Print("Sum: ")
	fmt.Println(totalSum)
	fmt.Print("Collapse: ")
	fmt.Println(collapse(totalSum))
	fmt.Print("Roman: ")

	Roman(collapse(totalSum))
	fmt.Println(" --Hail Caesar!")

}


//Michael's isPrime function

func isPrime(inNum int64) bool{
	var numCheck int64 = 3 //helps auto verify 1
	if (inNum % 2 == 0 && inNum != 2){
		return false
	}

	for{
		if numCheck*numCheck > inNum{
			break
		}
		
		if inNum % numCheck == 0{
			return false
		}

		numCheck = numCheck + 2
	}

	return true
}


//Michael's factor function

func factor(inNum int64) int64{

	var numhold int64 = 0 //holds on to the value of the input and allows to modify it 
	var sum int64 = 0 //stores the sum
	var count int = 0 //stores the count of factors
	var uniqueCount int = 0 //used to verify to make sure there is not more than one of each number
	var numCheck int64 = 0 //checks the number

	//Check the number of 2's in the factor tree
	numhold = inNum
	for{
		if numhold % 2 != 0{
			break
		}
		numhold = numhold / 2
		count = count + 1	//Keep track of factor count
		sum = sum + 2		//Add 2 two the sum of the middle factors
	}


	//Returns 0 if there are more than 2 middle factors
	if count > 1{
		return 0
	}


	numhold = inNum
	numCheck = 3

	//Check what other numbers can divide the input number
	for{
		// Using the square of the variable 'i' allows
		// for significatly shortening the run time
		// as a number times itself denotes the 'middle'
		// of possible products
	
		if numCheck * numCheck > inNum{
			break
		}


		// See how may times variable number 'i' 
        // can divide the input number
		for{
			if numhold % numCheck != 0{
				break
			}
			numhold = numhold / numCheck
			count = count + 1				//Track numer of factors
			sum = sum + numCheck			//Add number to sum of factors
			uniqueCount = uniqueCount + 1	//Track if the number is unique
		}


		// Return 0 if there are more than 2 factors
        // or if there are more than 1 of the factor
		if count > 2 || uniqueCount > 1{
			return 0
		}

		uniqueCount = 0
		numCheck = numCheck + 2
	}


	// If code gets this far there has only been one factor
    // Add it's complementary factor to the sum and return it


	sum = sum + (inNum / sum)
	return sum
} //  End factor function



//Zaina's collapse funtion

func collapse(i int64) int64 {

	var sum int64 //stores the sum of the number
	var num int64 //stores the number 
  var ans int64 //stores the return value

	num = i


	//if single digit 

	if((num%10) == num) {
			ans = num
			return ans
		
		} else {

		sum = 0


//do while loop
	for {

		//break down the number
    		sum = sum + (num%10)
		num = num/10
	

			if((num == 0)) {
				break
			}

	}
		return collapse(sum)
	}

}


//Aisha's roman function



func Roman(num int64) {

       var i int64 //temporary variable

        if num == 0 {

                fmt.Print("N")

        } else if num > 8 {

                for i =1; i <=10-num; i++{

                        fmt.Print("I")

        }

                fmt.Print("X")

        } else if num >5 {

                fmt.Print("V")

                for i =1; i<=num-5; i++{

                        fmt.Print("I")

        }

        } else if num > 3 {

                if num == 4{

                        fmt.Print("I")

        }

        fmt.Print("V")

        } else {

                for i =1; i<=num; i++{

                        fmt.Print("I")

        }

        }

        fmt.Println(" ")

}




