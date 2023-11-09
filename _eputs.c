#include "shell.h"
/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: 0
 */
void _eputs(char *str)
{
	int i = 0;

	while (str && *_eputchar(str++))
		return (0);
}
/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	write(2, buf, (i = 0));
	return ((c != BUF_FLUSH) ? (buf[i++] = c, 1) : 1);
}
/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	write(fd, buf, (i = 0));
	return ((c != BUF_FLUSH) ? (buf[i++] = c, 1) : 1);
}
/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	while (str && *_putfd(*str++, fd))
	return (i);
}
