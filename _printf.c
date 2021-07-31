#include "holberton.h"
#include <stdlib.h>

/**
 * get_specifier - selects the correct function to perform the operation asked
 * by the user
 *
 * @format: convert specifier passed as argument to the program
 * Return: a pointer to the function that corresponds to the convert specifier
 * given as a parameter. If s does not match any of the them return NULL.
 */
int (*get_specifier(const char *format))(va_list)

{
unsigned int i;
print_t p[] = {
{"c", print_char},
{"s", print_str},
{"%", print_nothing},
{"d", print_integer},
{"i", print_integer},
{"b", print_binary},
{"u", print_unsigneddecimal},
{"o", print_unsigneedoctal},
{"x", print_unsignedhexal},
{"X", print_unsignedhexacap},
{"p", print_voidpointerinhexa},
{"S", print_S},
{"r", print_reversedstr},
{"R", print_R}
{NULL, NULL}
};
		
for (i = 0 ; p[i].t != NULL ; i++)
{
if (*(p[i].t) == *format)
{
break;
}
}
return (p[i].f);
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
int (*f)(va_list);
unsigned int i = 0, len = 0;

if (format == NULL)
return (-1);


va_start(listvar, format);

while (format[i])
{
for (; format[i] != '%' && format[i]; i++)
{
_putchar(format[i]);
len++;
}
if (!format[i])
return (len);

f = check_for_specifiers(&format[i + 1]);
if (f != NULL)
{
len += f(valist);
i += 2;
continue;
}

if (!format[i + 1])
return (-1);
_putchar(format[i]);
len++;
if (format[i + 1] == '%')
i += 2;
else
i++;
}
va_end(listvar);
return (len);
}
