#include "holberton.h"


/**
 * main - entry point
 * @argc: Number of arguments
 * @argv: Argument vector
 * Return: EXIT_SUCCESS if succesful, EXIT_FAILURE if not
 */
int main(int argc, char *argv[])
{
	char *result;

	if (argc != 3 || !is_numerical(argv[1]) || !is_numerical(argv[2]))
	{
		write(STDOUT_FILENO, "Error\n", 6);
		exit(98);
	}

	result = mul_strings(argv[1], argv[2]);
	write(STDOUT_FILENO, result, _strlen(result));
	write(STDOUT_FILENO, "\n", 1);

	free(result);
	return (EXIT_SUCCESS);
}

/**
 * mul_strings - Multiplies two decimal numbers represented as strings
 * @str1: Pointer to string representing the first number
 * @str2: Pointer to string representing the second number
 * Return: Pointer to string representing the product
 */
char *mul_strings(char *str1, char *str2)
{
	char buffer[BUFFER_SIZE + 1];
	int len1, len2, ind1, ind2, n = 0, place;

	while (n < BUFFER_SIZE)
		buffer[n++] = '0';
	buffer[n] = 0;

	len1 = _strlen(str1);
	len2 = _strlen(str2);
	for (ind1 = len1 - 1; ind1 >= 0; ind1--)
	{
		for (ind2 = len2 - 1; ind2 >= 0; ind2--)
		{
			n = (str1[ind1] - 48) * (str2[ind2] - 48);
			place = (len1 - ind1) + (len2 - ind2);
			add_to_string(buffer, n, place);
		}
	}

	n = 0;
	while (buffer[n] && buffer[n] == '0')
		n++;

	if (n == BUFFER_SIZE)
		return (_strdup("0"));
	return (_strdup(buffer + n));
}

/**
 * _strdup - Duplicates a string
 * @str: String to be duplicated
 * Return: Pointer to start of new string
 */
char *_strdup(char *str)
{
	char *new;
	int i = 0;

	new = malloc(_strlen(str) + 1);
	if (new == NULL)
		exit(EXIT_FAILURE);

	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;

	return (new);
}

/**
 * add_to_string - Adds an integer to a string representation of an integer
 * @buf: String representation of a number
 * @n: Integer to add to @buf with all trailing zeros removed
 * @place: The number of trailing zeros @n would have. Ex. if n were
 *	   representing the number 15000, @n would be 15 and @place would be 3.
 */
void add_to_string(char buf[], int n, int place)
{
	int ind, sum;

	ind = BUFFER_SIZE - place + 1;
	while (n > 0)
	{
		sum = (n % 10) + (buf[ind] - 48);
		buf[ind] = sum % 10 + 48;
		buf[ind - 1] = buf[ind - 1] + sum / 10;
		n /= 10;
		ind--;
	}
}

/**
 * _strlen - String length
 * @str: Pointer to start of string to count the length of
 * Return: Length of the string
 */
int _strlen(char *str)
{
	int length = 0;

	while (*(str + length))
		length++;

	return (length);
}

/**
 * is_numerical - Test if string contains only numerical digits
 * @str: String to test
 * Return: 1 if @str only contains numerical digits, 0 otherwise.
 */
unsigned int is_numerical(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}
