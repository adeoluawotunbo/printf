#include "holberton.h"
#include <stdlib.h>

/**
 * _printf - the main function
 * @format: pointer to a string with conversion specifiers
 *
 * Description: produce output according to a format as the selected conversion
 * specifiers
 * Return: 0 success
 */

int _printf(const char *format, ...)

{
va_list listVar;
int (*fun_ptr)(va_list);
int positionFormat, len;

va_start(listVar, format);
positionFormat = 0;

while (format != NULL && format[positionFormat] != '\0')
{

if (format[positionFormat] != '%')

{
_putchar (format[positionFormat]);
positionFormat++;
continue;
}

fun_ptr = get_specifier(format + positionFormat + 1);
if (fun_ptr != NULL)

{
fun_ptr(listVar);
positionFormat++;
}

else

_putchar(format[positionFormat]);
positionFormat++;
}

len = positionFormat;
va_end(listVar);
return (len);
}

/**
 * get_specifier - the main function
 * @s: convert specifier passed as argument to the program
 *
 * Desciption: selects the correct function to perform the operation asked
 * by the user.
 * Return: a pointer to the function that corresponds to the convert specifier
 * given as a parameter. If s does not match any of the them return NULL.
 */

int (*get_specifier(const char *s))(va_list)
{
list_specifiers array_specifiers[] = {
{"c", print_char},
{"s", print_str},
{"%", print_percent},
{"d", print_integer},
{"i", print_integer},
{NULL, NULL}
};

int i = 0;
int len;

for (len = 0 ; array_specifiers[len].specifier != NULL ; len++)
                ;
while (i < len)
{
if (*s == *array_specifiers[i].specifier)
return (array_specifiers[i].f);
i++;
}
return (NULL);
}


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
