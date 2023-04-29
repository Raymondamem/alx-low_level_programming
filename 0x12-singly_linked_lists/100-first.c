#include <stdio.h>

void __attribute__ ((constructor)) void_setup(void);

/*
 * void_setup - function to be called befor main
 */
void void_setup(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
