#include "substring.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * find_substring - find substring of concatenated word list
 * Description: Finds all the possible substrings containing a list of words
 * within a given string
 * @s: The string to scan
 * @words: Array of words all substrings must be a concatneation arrangement of
 * @nb_words: Number of words in @words
 * @n: Holds the address at which to store the number of elements in the
 *     returned array
 * Return: An allocated array, storying each index at which a substring was
 *         found. If no solution is found, NULL is returned.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	(void)s;
	(void)words;
	(void)nb_words;
	*n = 0;
	return (NULL);
}
