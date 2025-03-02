#include "palindrome.h"

/**
 * is_palindrome - Function that checks if a number is palindrome
 * @n: number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long original_number = n;
	unsigned long reversed_number = 0;
	unsigned long temp = original_number;

	while (temp != 0)
	{
		reversed_number = reversed_number * 10 + temp % 10;
		temp /= 10;
	}

	return ((original_number == reversed_number) ? 1 : 0);
}
