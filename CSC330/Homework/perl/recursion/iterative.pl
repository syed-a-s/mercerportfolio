#!/usr/bin/perl

sub fact {
 my $val = $_[0];
 if ( $val < 0 )
 {
   return "-- ERROR --\n";
 }
 elsif ( $val == 0 || $val == 1) {
    return 1
 }
 else {
    my $factval = 1;
    for ( my $i= $val; $i>0; $i-- ) {
       $factval = $factval * $i;
       }
    return $factval
   }
}

# Take the command line input, compute the factorial of it, and print
# it out.
print fact($ARGV[0]) . "\n";