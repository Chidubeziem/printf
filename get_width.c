#include "main.h"

/**
 *
 *get_width - Calculates the width for printing
 *
 *@format: Formatted string
 *@i: List of arguments to be printed.
 *@list: list of arguments.
 *
 *Return: width.
 *
 */
int get_width(const char *format, int *i, va_list list)
{
	int alx;
	int width = 0;

	for (alx = *i + 1; format[alx] != '\0'; alx++)
	{
		if (is_digit(format[alx]))
		{
			width *= 10;
			width += format[alx] - '0';
		}
		else if (format[alx] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = alx - 1;
	return (width);
}
