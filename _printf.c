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
