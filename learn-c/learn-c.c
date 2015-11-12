// learn-c.c : Defines the entry point for the console application.
//

#include <stdio.h>

int main()
{
	int c;
	char c2;

	char greetings[] = "Hi there!, please type a single character";
	puts(greetings);

	c = getchar();
	printf("You typed '%c', which is '%x' in hex, and '%d' in dec.\n", c, c, c);

	c2 = (char)c;
	printf("After casting 'c' value as a char, c2 value is %c\n", c2);
    return 0;
}