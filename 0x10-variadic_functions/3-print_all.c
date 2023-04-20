#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list args;
	char *str;
	int i = 0;
	char format_char;

	va_start(args, format);
	while (format && format[i])
	{
		format_char = format[i];
		switch (format_char)
		{
			case 'c':
			printf("%c", va_arg(args, int));
			break;
			case 'i':
			printf("%d", va_arg(args, int));
			break;
			case 'f':
			printf("%f", va_arg(args, double));
			break;
			case 's':
			str = va_arg(args, char *);
			if (str == NULL)
			str = "(nil)";
			printf("%s", str);
			break;
			default:
			i++;
			continue;
		}
		if (format[i + 1] != '\0')
		printf(", ");
		i++;
	}
	printf("\n");
	va_end(args);
}
