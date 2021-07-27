#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct list_specifiers - structure of format which receives the _printf
 * function
 * @specifier: character that represent the format specifier
 * @f: Pointer to a function associated to the format specifier
 */

typedef struct list_specifiers
{
char *specifier;
int (*f)();
} list_specifiers;

int _putchar(char c);
int _printf(const char *format, ...);
int _strlen(char *s);
int (*get_specifier(const char *s))(va_list);
int print_str(va_list s);
int print_char(va_list c);
int print_integer(va_list list);
int print_percent(va_list perc);

#endif
