#!usr/bin/perl
use strict;
use warnings;

# function

sub isPrime { 
      
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

# function call

 	print "Choose a positive integer : ";
	chomp(my $input = <>);
 	
 	my $status = isPrime($input);

 	if ($status == 1){ 
 		print $input, " is a prime number\n\n";
 	} else {
 		print $input, " is not a prime number\n\n";
	}
