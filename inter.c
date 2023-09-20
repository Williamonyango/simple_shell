#include "shell.h"
/**
 *interact - returns true if the shell is interactive
 *@inf: address of the structure.
 *Return: 1 if in interactive mode
 *0 if not interactive
 */
int interact(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * delim - checks if character is a delimeter
 * @ch: the character to check
 * @delimstr: the delimeter string
 * Return: 1 if true, 0 if false
 */
int delim(char ch, char *delimstr)
{
	while (*delimstr)
		if (*delimstr++ == c)
			return (1);
	return (0);
}

/**
 * _isalphabet - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalphabet(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * strint - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int strint(char *s)
{
	int b, sign = 1, flag = 0, output;
	unsigned int result = 0;

        while (b = 0; s[b] != '\0' && flag != 2; b++)
	{
		if (s[b] == '-')
			sign *= -1;

		if (s[b] >= '0' && s[b] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[b] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

