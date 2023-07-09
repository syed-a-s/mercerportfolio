#!usr/bin/perl
use strict;
use warnings;

# Checks if numbered shifted is prime
sub IsPrime { 
      
	my $num = shift;
	my $status = 1;

	for (my $i = 2; $i < $num; $i++) {		
		if($num % $i == 0) {
			$status = 0;
			last;
		}	
	}

	return $status;
}

# Find the norm of 3 numbers
sub NormOf { 

  my ($i, $j, $k) = (@_);
  my $norm = sqrt(($i*$i) + ($j*$j) + ($k*$k));
  return $norm;

}

# Main function

  print "Enter an odd number greater than 7 : ";
  chomp(my $userInput = <>);
  
  if(($userInput > 7) and ($userInput % 2 == 1)) { 
    
    my @primeNums;
    
    # Storing all prime numbers from 1 to userInput
    for(my $i = 1; $i < $userInput; $i++) { 
      if(IsPrime($i)) { 
        push(@primeNums, $i);
      }
    }
    
    # Finding the minimun norm of the triplet sums 
    my $l, my $r, my $norm = 9999;
    my @triplet; $triplet[2] = 0;
    
    for(my $i = 0; $i < (scalar @primeNums) - 2; $i++) { 
      $l = $i + 1;
      $r = (scalar @primeNums) - 1;
      while($l < $r) { 
        if($primeNums[$i] + $primeNums[$l] + $primeNums[$r] == $userInput) { 
          if(NormOf($primeNums[$i], $primeNums[$l], $primeNums[$r]) <= $norm) { 
            $norm = NormOf($primeNums[$i], $primeNums[$l], $primeNums[$r]);
            $triplet[0] = $primeNums[$i];
            $triplet[1] = $primeNums[$l];
            $triplet[2] = $primeNums[$r];
          } 
            $l++;
            $r--;     
        } elsif($primeNums[$i] + $primeNums[$l] + $primeNums[$r] < $userInput) {
              $l++;
        } else { 
              $r--;
        }
      }
    } 
        print ($userInput, " : ", "(", $triplet[0], ", ", $triplet[1], ", ", $triplet[2], ")" ); 
  } else { 
      print "Please enter an odd number greater than 7";
  }
