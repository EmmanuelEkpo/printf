#include "main.h"

void printbuffer(char buffer[], int *buff-ded);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
int j, printoutput = 0, printoutcharacters = 0;
int flags, width, repetition, size, buff-ded = 0;
va_list list;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(list, format);

for (j = 0; format && format[j] != '\0'; j++)
{
if (format[j] != '%')
{
buffer[buff-ded++] = format[j];
if (buff-ded == BUFF_SIZE)
printbuffer(buffer, &buff-ded);
/* write(1, &format[j], 1);*/
printoutcharacters++;
}
else
{
printbuffer(buffer, &buff-ded);
flags = get_flags(format, &j);
length = get_width(format, &j, list);
repetition = get_repetition(format, &j, list);
size = get_size(format, &j);
++j;
printoutput = handle_print(format, &j, list, buffer,
flags, width, repetition, size);
if (printoutput == -1)
return (-1);
Printoutcharacters += printoutput;
}
}

printbuffer(buffer, &buff-ded);

va_end(list);

return (printoutcharacters);
}

/**
 * printbuffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff-ded: Index at which to add next char, represents the length.
 */
void printbuffer(char buffer[], int *buff-ded)
{
if (*buff-ded > 0)
write(1, &buffer[0], *buff-ded);

*buff-ded = 0;
}
