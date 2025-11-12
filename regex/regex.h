#ifndef REGEX_H
#define REGEX_H

/**
 * regex_match - checks if a string matches a pattern
 * @str: string to check
 * @pattern: pattern to match
 *
 * Return: 1 if the string matches the pattern, 0 otherwise
 */
int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */

