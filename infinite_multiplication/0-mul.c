#include "holberton.h"
#include <stdlib.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: string
 * Return: 1 if only digits, 0 otherwise
 */
int is_digit(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

/**
 * _strlen - returns length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

/**
 * errors - handles errors for main
 */
void errors(void)
{
    char *err = "Error\n";
    int i = 0;

    while (err[i])
        _putchar(err[i++]);
    exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
    char *s1, *s2;
    int len1, len2, len, i, n1, n2, carry, *res, a = 0;

    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
        errors();
    s1 = argv[1], s2 = argv[2];
    len1 = _strlen(s1);
    len2 = _strlen(s2);
    len = len1 + len2 + 1;
    res = malloc(sizeof(int) * len);
    if (!res)
        return (1);
    for (i = 0; i < len; i++)
        res[i] = 0;
    for (len1 = len1 - 1; len1 >= 0; len1--)
    {
        n1 = s1[len1] - '0';
        carry = 0;
        for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
        {
            n2 = s2[len2] - '0';
            carry += res[len1 + len2 + 1] + (n1 * n2);
            res[len1 + len2 + 1] = carry % 10;
            carry /= 10;
        }
        if (carry > 0)
            res[len1 + len2 + 1] += carry;
    }
    for (i = 0; i < len - 1; i++)
    {
        if (res[i])
            a = 1;
        if (a)
            _putchar(res[i] + '0');
    }
    if (!a)
        _putchar('0');
    _putchar('\n');
    free(res);
    return (0);
}

