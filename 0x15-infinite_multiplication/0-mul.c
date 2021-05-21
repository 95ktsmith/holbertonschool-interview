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
	char buf[BUFFER_SIZE];
	int i = 0;

	if (argc != 3 || !is_numerical(argv[1]) || !is_numerical(argv[2]))
	{
		write(STDOUT_FILENO, "Error\n", 6);
		exit(98);
	}

	while (i < BUFFER_SIZE)
		buf[i++] = '0';

	result = mul_strings(argv[1], argv[2], buf);
	if (result == NULL)
		write(STDOUT_FILENO, "0\n", 2);
	else
	{
		write(STDOUT_FILENO, result, BUFFER_SIZE - (result - buf));
		write(STDOUT_FILENO, "\n", 1);
	}

	exit(EXIT_SUCCESS);
}

/**
 * mul_strings - Multiplies two decimal numbers represented as strings
 * @str1: Pointer to string representing the first number
 * @str2: Pointer to string representing the second number
 * @buf: Buffer to store the result in
 * Return: Pointer to first character of the number in the buffer
 */
char *mul_strings(char *str1, char *str2, char buf[])
{
	int len1, len2, ind1, ind2, n = 0, place;

	len1 = _strlen(str1);
	len2 = _strlen(str2);
	for (ind1 = len1 - 1; ind1 >= 0; ind1--)
	{
		for (ind2 = len2 - 1; ind2 >= 0; ind2--)
		{
			n = (str1[ind1] - 48) * (str2[ind2] - 48);
			place = (len1 - ind1) + (len2 - ind2);
			add_to_string(buf, n, place);
		}
	}

	while (n < BUFFER_SIZE && buf[n] == '0')
		n++;

	if (n == BUFFER_SIZE)
		return (NULL);
	return (&buf[n]);
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
	if (_strlen(str) < 1)
		return (0);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}
