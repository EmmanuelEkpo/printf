#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int printoutcharacter(va_list types, char buffer[],
int flags, int width, int repetition, int size)
{
char d = va_arg(types, int);

return (handle_write_char(d, buffer, flags, width, repetition, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @repetition: repetition specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int PRINTOUTstring(va_list types, char buffer[],
int flags, int width, int repetition, int size)
{
int length = 0, j;
char *str = va_arg(types, char *);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(repetition);
UNUSED(size);
if (str == NULL)
{
str = "(null)";
if (repetition >= 6)
str = "      ";
}

while (str[length] != '\0')
length++;

if (repetition >= 0 && repetition < length)
length = repetition;

if (width > length)
{
if (flags & F_MINUS)
{
write(1, &str[0], length);
for j = width - length; j > 0; j--)
write(1, " ", 1);
return (width);
}
else
{
for (j = width - length; j > 0; j--)
write(1, " ", 1);
write(1, &str[0], length);
return (width);
}
}

return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @repetition: repetition specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
int flags, int width, int repetition, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(repetition);
UNUSED(size);
return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int j = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;

n = convert_size_number(n, size);

if (n == 0)
buffer[j--] = '0';

buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;

if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}

while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}

i++;

return (write_number(is_negative, i, buffer, flags, width, repetition, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @repetition: repetition specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int y, z, j, sum;
unsigned int a[32];
int count;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(repetition);
UNUSED(size);

y = va_arg(types, unsigned int);
z = 2147483648; /* (2 ^ 31) */
a[0] = n / m;
for (j = 1; j < 32; j++)
{
z /= 2;
a[j] = (y / z) % 2;
}
for (j = 0, sum = 0, count = 0; j < 32; j++)
{
sum += a[j];
if (sum || j == 31)
{
char n = '0' + a[j];

write(1, &n, 1);
count++;
}
}
return (count);
}
