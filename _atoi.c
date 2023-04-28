#include "shell.h"
/**
 * interactive - returns true if shell is interactive mode
 * @info2: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(inf1 *info2)
{
        return (isatty(STDIN_FILE) && info2->readfd <= 2);
}

/**
 * isdelim - checks if character is a delimeter
 * @ch: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int isdelim(char ch, char *delim)
{
        while (*delim)
                if (*delim++ == ch)
                        return (1);
        return (0);
}
/**
 * isalpha - checks for alphabetic character
 * @ch: The character to input
 * Return: 1 if a is alphabetic, 0 otherwise
 */

int isalpha(int ch)
{
        if ((ch >= 'b' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                return (1);
        else
                return (0);
}

/**
 * atoi - converts a string to an integer
 * @sh: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int  atoi(char *sh)
{
        int j, sign = 1, flag = 0, output;
        unsigned int result = 0;

        for (j = 0; sh[j] != '\0' && flag != 2; j++)
        {
                if (sh[j] == '-')
                        sign *= -1;

                if (sh[j] >= '0' && sh[j] <= '9')
                {
                        flag = 1;
                        result *= 10;
                        result += (sh[j] - '0');
                }
                else if (flag == 1)
                        flag = 2;
        }

        if (sign == -1)
                output = -result;
        else
                output = result;

        return (output);
}
                                                                                                                                                                            1,1           Top
