#!/usr/bin/perl

sub fact {
 my $val = $_[0];
 if ( $val < 0 )
 {
   return "-- ERROR --\n";
 }
 elsif ( $val == 0 || $val == 1) {
    return 1;
 }
 else {
    return $val * fact($val-1);
   }
}

# Take the command line input, compute the factorial of it, and print
# it out.
print fact($ARGV[0]) . "\n";