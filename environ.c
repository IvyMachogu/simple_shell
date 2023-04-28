#include "shell.h"

/**
 * env - prints the current environment
 * @inf: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int env(info1 *inf)
{
	print_list_str(inf->env);
	return (0);
}

/**
 * getval - gets the value of an environ variable
 * @inf: Structure containing potential arguments. Used to maintain
 * @name: env var name
 * Return: the value
 */
char *getval(info1 *inf, const char *name)
{
	list_t *node = inf->env;
	char *h;

	while (node)
	{
		h = starts_with(node->str, name);
		if (h && *h)
			return (h);
		node = node->next;
	}
	return (NULL);
}

/**
 * newenvvar - Initialize a new environment variable,
 *             or modify an existing one
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int newenvvar(info1 *inf)
{
	if (inf->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (setenv(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}
/**
 * _unsetenv - Remove an environment  variable
 * @inf: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * return:Always 0
 */
int _unsetenv(info1 *inf)
{
	int a;

	if (inf->argc == 1)
	{
		_eputs("too few arguments.\n"
				return (1);
				}
				for (a = 1; a <= inf->argc; a++)
				unsetenv(inf, inf->argv[a];
					return (0);
					}
/**
 * popenvlist -populates env linked list
 * @inf: Structure Containing potential arguments. used to maintain
 * constant function prototype.
 * Return: Always 0.
 */
int popenvlist(info1 *inf)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[a], 0);
	inf->env = node;
	return (0);
}
