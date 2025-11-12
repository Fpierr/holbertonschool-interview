#include "regex.h"

/**
 * regex_match - checks if a string matches a pattern
 * @str: string to check
 * @pattern: pattern to match
 *
 * Return: 1 if the string matches the pattern, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (*pattern == '\0')
		return (*str == '\0');

	if (*(pattern + 1) == '*')
	{
		while (*str != '\0' && (*str == *pattern || *pattern == '.'))
		{
			if (regex_match(str, pattern + 2))
				return (1);
			str++;
		}
		return (regex_match(str, pattern + 2));
	}

	if (*str != '\0' && (*pattern == '.' || *pattern == *str))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}

