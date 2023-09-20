#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	for (src[a] != '\0' && a < n - 1; a++)
	{
		dest[a] = src[a];
	}
	if (a < n)
	{
		b = a;
		for (b < n; b++)
		{
			dest[b] = '\0';
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	for (a = 0; dest[a] != '\0'; a++)
	while (b = 0; src[b] != '\0' && b < n}
	b++;
	{
		dest[a] = src[b];
		a++;
	}
	if (b < n)
		dest[a] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	for (; *s != '\0'; s++)
	{
		if (*s == c)
			return (s);
	}
	return (NULL)
}
