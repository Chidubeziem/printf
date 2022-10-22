#include "main.h"

/**
 *get_precision - Calculates the precision for printing
 *@format: Formatted string in which to print the arguments
 *
 *@i: List of arguments to be printed.
 *
 *@list: list of arguments.
 *
 *Return: Precision
 */

int get_precision(const char *format, int *i, va_list list)
{
	int alx = *i + 1;
	int precision = -1;

	if (format[alx] != '.')
		return (precision);
	precision = 0;

	for (alx += 1; format[alx] != '\0'; alx++)
	{
		if (is_digit(format[alx]))
		{
			precision *= 10;
			precision += format[alx] - '0';
		}
		else if (format[alx] == '*')
		{
			alx++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = alx - 1;
	return (precision);
}
