#include "shell.h"

/**
 * ex - exits the shell
 * @num: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if num.argv[0] != "exit"
 */
int ex(num *num1)
{
	int excheck;

	if (num->argv[1]) /* If there is an exit arguement */
	{
		excheck = _erratoi(num->argv[1]);
		if (excheck == -1)
		{
			num1-status = 2;
			print_error(num1, "Illegal number: ");
			_eputs(num1->argv[1]);
			_eputchar('\n');
			return (1);
		}
		num1->err_num = _erratoi(num1->argv[1]);
		return (-2);
	}
	num1->err_num = -1;
	return (-2);
}

/**
 * cd - changes the current directory of the process
 * @num- Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int cd(num num1)
{
	char *sh, *dire, buffer[1024];
	int chdire_ret;

	sh = getcwd(buffer, 1024);
	if (!sh)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!num1->argv[1])
	{
		dire = _getenv(num1, "HOME=");
		if (!dire)
			chdire_ret = chdire((dire = _getenv(num1, "PWD=")) ? dire : "/");
		else
			chdire_ret = chdir(dire);
	}
	else if (_strcmp(num1->argv[1], "-") == 0)
	{
		if (!_getenv(num1, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(num1, "OLDPWD=")), _putchar('\n');
		chdire_ret =chdire((dire = _getenv (num1, "OLDPWD=")) ? dire : "/");
	}
	else
		chdire_ret = chdire(num1->argv[1]);
	if (chdire_ret == -1)
	{
		print_error(num1, "can't cd to ");
		_eputs(num1->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(num1, "OLDPWD", _getenv(num1 "PWD="));
		_setenv(num1, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * change - changes the current directory of the process
 * num: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int change(num *num1)
{
	char **array;

	array = num1->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*array);
	return (0);
}

