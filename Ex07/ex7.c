#include <stdio.h>

int main(int argc, char* argv[])
{
	int bugs = 100;
	double bug_rate = 1.2;

	printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);

	long universe_of_defects = 1L * 1024L * 1024L * 1024L;
	printf("The entire universe has %ld bugs.\n", universe_of_defects);

	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs.\n", expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
	printf("That is only a %e portion of the universe.\n", part_of_universe);

	// This makes no sense, just a demo of something wierd
	char nul_byte = '\0';					// Make a character with a special syntax that creates a 'nul byte' character.  This is effectively the number 0.
	int care_percentage = bugs * nul_byte;	// Produces 0 which demonstrates an ugly hack you find sometimes.
	printf("Which means you should care %d%%.\n", care_percentage);	// The %% at the end is what allows you to print out a '%' (percent) character.

	return 0;
}
