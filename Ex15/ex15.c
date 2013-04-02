#include <stdio.h>

int main(int argc, char* argv[])
{
	// Create two arrays we care about
	int ages[] = {23, 43, 12, 89, 2};
	char* names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	// first wa using indexing
	for(i = 0; i < count; i++)
	{
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	printf("---\n");

	// setup the pointers to the start of the arrays
	int* cur_age = ages;
	char** cur_name = names; 
	// A char* is already a pointer to char, which is just a string.
	// However, you need 2 levels since names is 2-dimensional
	// char** is a "pointer to (a pointer to char)" type

	// second way using pointers
	for(i = 0; i < count; i++)
	{
		printf("%s is %d years old.\n", *(cur_name+i), *(cur_age+i));
		// *(cur_name+i) is the same thing as writing name[i]
		// read as "the value of (pointer cur_name plus i)"
	}

	printf("---\n");

	// third way, pointers are just arrays
	for(i = 0; i < count; i++)
	{
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
	}

	printf("---\n");

	// fourth way with pointers in a stupid complex way using pointer arithmetic
	// initialize for-loop by setting cur_name and cur_age to the beginning of
	// the names and age arrays.
	// The test portion of the for-loop then compares the distance of the
	// pointer cur_age from the start of ages.
	// The pointers cur_name and cur_age are now pointing at one element of
	// the arrays they work on, and we can print them out using *cur_name and
	// *cur_age which means "The value of wherever cur_name is pointing"
	for(cur_name = names, cur_age = ages; 
		(cur_age - ages) < count; 
		cur_name++, cur_age++)
	{
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}

	return 0;
}
