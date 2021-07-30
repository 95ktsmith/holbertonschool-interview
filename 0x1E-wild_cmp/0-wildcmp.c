#include "holberton.h"


/**
 * wildcmp - Wildcard Compare
 * @s1: First string
 * @s2: Second string, can contain wildcard caharacter
 * Return: 1 if the two strings are considered identical, 0 if not.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == 0 && *s2 == 0)
		return (1);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
	{
		if (*s1 == 0)
			return (wildcmp(s1, s2 + 1));

		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}

	return (0);
}
