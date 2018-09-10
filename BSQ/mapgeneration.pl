# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mapgeneration.pl                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkhrazz <fkhrazz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 12:48:50 by fkhrazz           #+#    #+#              #
#    Updated: 2018/09/10 13:48:11 by fkhrazz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/perl
use warnings;
use strict;
die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print "o";

		}
		else {
			print ".";

		}

	}
	print "\n";
}