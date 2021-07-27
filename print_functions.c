#include "holberton.h"
/**
 *print_char - prints a char
 *@c: char argument of the list
 *Return: Length of a char
 */
int print_char(va_list c)
{
	_putchar(va_arg(c, int));
	return(1);
}

/**
 * print_integer - prints the passed integer from the variadic function
 * @list: list of variadic function
 *
 * Return: Length of the interger being printed.
 */
int print_integer(va_list list)
{
	int n = va_arg(list, int);
	int count = 0;
	unsigned int i, current_digit;

	/* Edge case n is cero */
	if (n == 0)
	{
		_putchar('0');
		count++;
		return (count);
	}
	/* Case for negative integer: print '-' and turn int to positive */
	if (n < 0)
	{
		_putchar('-');
		count++;
		n = n * (-1);
	}
	/* Finds the power of the integer*/
	for (i = 1; n / i > 9; i = i * 10)
	{
	}
	/* Prints each digit */
	for (; i > 0; i = i / 10)
	{
		current_digit = n / i;
		n = n % i;
		_putchar('0' + current_digit);
		count++;
	}
	return (count);
}

/**
 * print_percent - prints a percentage sign
 * @perc: void
 * Return: Length of a percentage
 */
int print_percent(va_list perc)
{
	_putchar('%');
	(void) perc;
	return(1);
}

/**
 *  print_str - prints a string
 *
 * @s: a pointer to a string we want to print
 * Return: if str is NULL return length of the valriable null
 * if not, return the length of the string.
 */
int print_str(va_list s)
{
	int i, c, len;
	char *str;
	char *null;

	str = va_arg(s, char*);
	if (str == NULL)
	{
		null = "(null)";
		for (i = 0 ; null[i] != '\0' ; i++)
			_putchar(null[i]);
		len = _strlen(null);
	}
	else
	{
		for (c = 0 ; str[c] != '\0' ; c++)
			_putchar(str[c]);
		len = _strlen(str);
	}
	return(len);
}


/**
 * _strlen -  returns the length of a string
 *
 * @s: a pointer to a string we want to know the length
 * Return: The length of a string
 */
int _strlen(char *s)
{
	int size;

	for (size = 0 ; s[size] != '\0' ; size++)
	{
		;
	}
	return (size);
}
