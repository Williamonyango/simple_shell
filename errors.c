#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */
void _eputs(char *str)
{
  int a;

  if (!str)
    return;
  for (a = 0; str[a] != '\0'; a++)
    {
      _eputchar(str[i]);
    }
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
  static int a;
  static char buf[WRITE_BUF_SIZE];

  if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
    {
      write(2, buf, a);
      a = 0;
    }
  else
    {
      buf[a++] = c;
    }
  return (1);
}

/**
 * _putfid - writes the character c to given fid
 * @c: The character to print
 * @fid: The filedescriptor to write to
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately.
 */
int _putfid(char c, int fid)
{
  static int a;
  static char buf[WRITE_BUF_SIZE];

  if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
    {
      write(fid, buf, a);
      a = 0;
    }
  else
    {
      buf[a++] = c;
    }
  return (1);
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
  int a = 0;

  if (!str)
    return (0);
  while (*str)
    {
      a += _putfd(*str++, fd);
    }
  return (a);
}
