#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
void print_arguments(int argc, char* argv[]);
void print_letters(char arg[]);

int main(int argc, char* argv[])
{
	print_arguments(argc, argv);

	return 0;
}

void print_arguments(int argc, char* argv[])
{
	for(int i = 0; i < argc; i++)
	{
		print_letters(argv[i]);
	}
}

void print_letters(char arg[])
{
	int length = strlen(arg);
	for(int i = 0; i < length; i++)
	{
		char ch = arg[i];

		if(isalpha(ch) || isblank(ch))
		{
			printf("'%c' == %d ", ch, ch);
		}
	}

	printf("\n");
}
