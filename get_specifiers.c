#include "holberton.h"

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
