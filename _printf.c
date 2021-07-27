#include "holberton.h"
#include <stdlib.h>

/**
 * get_specifier - selects the correct function to perform the operation asked
 * by the user
 *
 * @s: convert specifier passed as argument to the program
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
 * _printf - produce output according to a format as the selected conversion
 * specifiers
 * @format: pointer to a string with conversion specifiers
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
