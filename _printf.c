#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function to produce output according to a format.
 *
 * @format: Format string.
 *
 * Return: The number of characters printed (excluding the null byte
 * used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	char *str_arg;
	char char_arg;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				str_arg = va_arg(args, char *);
				while (*str_arg)
				{
					count += write(1, str_arg, 1);
					str_arg++;
				}
			}
			else if (*format == 'c')
			{
				char_arg = va_arg(args, int);
				count += write(1, &char_arg, 1);
			}
			else if (*format == '%')
			{
				count += write(1, "%", 1);
			}
			else
			{
				/* Invalid specifier */
				return (-1);
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
