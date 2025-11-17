#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * check_match - verifies if substring starting at index matches words
 * @s: input string
 * @words: array of words
 * @nb_words: number of words
 * @word_len: length of each word
 * Return: 1 if valid match, otherwise 0
 */
static int check_match(const char *s, const char **words,
		       int nb_words, int word_len)
{
	int i, j, found;
	int *used = calloc(nb_words, sizeof(int));

	if (used == NULL)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		found = 0;

		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] && strncmp(s + i * word_len,
						words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}

		if (!found)
		{
			free(used);
			return (0);
		}
	}

	free(used);
	return (1);
}

/**
 * find_substring - finds indices of all concatenations
 * @s: input string
 * @words: array of words
 * @nb_words: number of words
 * @n: number of matches found
 * Return: int array of starting indices, or NULL
 */
int *find_substring(char const *s, char const **words,
		    int nb_words, int *n)
{
	int i, s_len, word_len, total_len, *indices, count = 0;

	if (!s || !words || nb_words <= 0)
	{
		*n = 0;
		return (NULL);
	}

	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	s_len = strlen(s);

	if (s_len < total_len)
	{
		*n = 0;
		return (NULL);
	}

	indices = malloc(sizeof(int) * (s_len - total_len + 1));
	if (!indices)
	{
		*n = 0;
		return (NULL);
	}

	for (i = 0; i <= s_len - total_len; i++)
	{
		if (check_match(s + i, words, nb_words, word_len))
		{
			indices[count] = i;
			count++;
		}
	}

	if (count == 0)
	{
		free(indices);
		*n = 0;
		return (NULL);
	}

	*n = count;
	return (indices);
}

