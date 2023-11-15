#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fff: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fff_t fff_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fff_types[i].fff != '\0'; i++)
		if (fff[*ind] == fff_types[i].fff)
			return (fff_types[i].fn(list, buffer, flags, width, precision, size));

	if (fff_types[i].fff == '\0')
	{
		if (fff[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fff[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fff[*ind] != ' ' && fff[*ind] != '%')
				--(*ind);
			if (fff[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fff[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
50,1          dBot
