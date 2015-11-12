// learn-c.c : Defines the entry point for the console application.
//

#include <stdio.h>

int main()
{
	int c;
	char c2;

	int* c_ptr;		// pointer to an int
	char* c2_ptr;	// pointer to a char

	char greetings[] = "Hi there!, please type a single character";
	puts(greetings);

	c = getchar();
	printf("You typed '%c', which is '%x' in hex, and '%d' in dec.\n", c, c, c);

	c2 = (char)c; // casting the value of c as a char
	printf("After casting 'c' value as a char, c2 value is %c\n", c2);

	c_ptr = &c; 
	c2_ptr = &c2;

	printf("The variable 'c' is at address '0x%08x'\n", c_ptr);
  	printf("The variable 'c2' is at address '0x%08x'\n", c2_ptr);
  	
	return 0;
}