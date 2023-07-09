#!usr/bin/perl
use strict;
use warnings;

print "Choose a postive integer : ";
my $num = <>;

for (my $i = 1; $i <= $num; $i++) { 
      print $i, " ";
}
print "\n";