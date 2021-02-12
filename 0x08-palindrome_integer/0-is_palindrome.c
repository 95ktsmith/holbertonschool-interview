#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome or not
 * @n: The number to check
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long num = n, rev = 0;

	while (num > 0)
	{
		rev *= 10;
		rev += num % 10;
		num /= 10;
	}

	return (n == rev);
}
