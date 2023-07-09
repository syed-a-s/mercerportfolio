use strict;
use warnings;

sub Hello {
	my $args = shift;
	return $args;
}

my $num = Hello(5);
print $num;
