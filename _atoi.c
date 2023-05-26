#include "shell.h"
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);
/**
 * interactive - returns true if shell is interactive
 * @info: struct address
 * Return: 1 if interactive, else 0
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - checks if character is a delimiter
 * @c: character that is being checked
 * @delim: delimiter string
 * Return: 1 if true, 0 if it is false'
 */
int is_delim(char c, char *delim)
{
while (*delim)
{
if (*delim++ == c)
{
return (1);
}
}
return (0);
}
/**
 * _isalpha - checks for alphabetic character
 * @c: character that is being checked
 * Return: 1 if character is alphabetic, else 0
 */
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
{
return (1);
}
else
{
return (0);
}
}
/**
 * _atoi - converts string to an integer
 * @s: string that is being converted
 * Return: 0 if no numbers in string
 */
int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;
for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
{
sign *= -1;
}
if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
{
flag = 2;
}
}
if (sign == -1)
{
output = -result;
}
else
{
output = result;
}
return (output);
}
