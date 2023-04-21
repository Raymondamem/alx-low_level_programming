#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything.
 * @format: a list of types of arguments passed to the function
 * c: char
 * i: integer
 * f: float
 * s: char * (if the string is NULL, print (nil) instead
 * any other char should be ignored
 * Return: void
 */
void print_all(const char * const format, ...)
{
    va_list args;
    unsigned int i = 0, j;
    char *separator = "";

    data_t data[] = {
        {"c", format_c},
        {"i", format_i},
        {"f", format_f},
        {"s", format_s},
        {NULL, NULL}
    };

    va_start(args, format);

    while (format && format[i])
    {
        j = 0;
        while (data[j].format)
        {
            if (*(data[j].format) == format[i])
            {
                printf("%s", separator);
                data[j].printer(args);
                separator = ", ";
                break;
            }
            j++;
        }
        i++;
    }
    printf("\n");
    va_end(args);
}

/**
 * format_c - prints a char
 * @args: a va_list
 */
void format_c(va_list args)
{
    printf("%c", va_arg(args, int));
}

/**
 * format_i - prints an integer
 * @args: a va_list
 */
void format_i(va_list args)
{
    printf("%d", va_arg(args, int));
}

/**
 * format_f - prints a float
 * @args: a va_list
 */
void format_f(va_list args)
{
    printf("%f", va_arg(args, double));
}

/**
 * format_s - prints a string
 * @args: a va_list
 */
void format_s(va_list args)
{
    char *str;

    str = va_arg(args, char *);
    if (str == NULL)
    {
        printf("(nil)");
        return;
    }
    printf("%s", str);
}
