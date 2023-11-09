#include "shell.h"

/**
 * _myenv - prints the current space
 * @info: Structure containing potential arguments,
 * used for maintaining constant functions.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - helps in getting the value of an environ variable
 * @info: Structure containing potential arguments for maintaining.
 * @name: env var name
 * Return: the perfect value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node && !(p = starts_with(node->str, name)))
		node = node->next;

	return (p && *p ? p : NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 * or modify the one existing.
 * @info: Structure containing potential arguments,
 * used to maintain constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	return ((info->argc == 3) ?  _setenv(info, info->argv[1], info->argv[2]) :
	(_eputs("Incorrect number of arguments\n"), 1));
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments,
 * used for maintaining constant function prototype.
 *  Return: Success
 */
int _myunsetenv(info_t *info)
{
	if (info->argc == 1)
		return (_eputs("Too few arguments.\n"), 1);
	for (int i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments,
 * used for maintaining constant function prototype.
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	for (size_t i = 0; environ[i]; i++)
		add_node_end(&info->env, environ[i], 0);

	return (0);
}

