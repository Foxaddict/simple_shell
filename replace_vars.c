#include "shell.h"

/**
 * is_chain - test if current char is active
 * @info: parameter structure
 * @buf: char buffer
 * @p: address
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if ((buf[j] == '|' && buf[j + 1] == '|') ||
	(buf[j] == '&' && buf[j + 1] == '&'))
{
		buf[j] = 0;
		info->cmd_buf_type = (buf[j] == '|') ? CMD_OR : CMD_AND;
		*p = ++j;
		return (1);
}
		else if (buf[j] == ';')
{
		buf[j++] = 0;
		info->cmd_buf_type = CMD_CHAIN;
		*p = j;
		return (1);
}
	return (0);
}

/**
 * check_chain - checks we should continue based on last section
 * @info: the parameter structure
 * @buf: the char
 * @p: address of current position
 * @i: starting position
 * @len: length
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if ((info->cmd_buf_type == CMD_AND && info->status) ||
(info->cmd_buf_type == CMD_OR && !info->status))
{
		buf[i] = 0;
		j = len;
}
	*p = j;
}

/**
 * replace_alias - replaces an aliases in the string
 * @info: the parameter structure
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	for (int i = 0; i < 10; i++)
{
		list_t *node = node_starts_with(info->alias, info->argv[0], '=');

		if (!node)
		return (0);
		free(info->argv[0]);
		info->argv[0] = _strdup(_strchr(node->str, '=') + 1);
}
	return (1);
}

/**
 * replace_vars - replaces vars in the string
 * @info: the parameter structure
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
for (int i = 0; info->argv[i]; i++)
{
if (info->argv[i][0] == '$' && info->argv[i][1])
{
if (!_strcmp(info->argv[i], "$?"))
replace_string(&(info->argv[i]), _strdup(convert_number(info->status, 10, 0)));
	else if ((!_strcmp(info->argv[i], "$$"))
replace_string(&(info->argv[i]), _strdup(convert_number(getpid(), 10, 0)));
	else if ((node_starts_with(info->env, &info->argv[i][1], '=') &&
replace_string(&(info->argv[i]), _strdup(_strchr(node->str, '=') + 1))) ||
replace_string(&info->argv[i], _strdup("")))
	continue;
}
}
	return (0);
}

/**
 * replace_string - replacing string
 * @old: old string
 * @new: new string
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
