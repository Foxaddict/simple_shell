#include "shell.h"
/**
 * _myhistory - function that displays the history list, one command by line,
 * preceded with line numbers, starting at 0.
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}
/**
 * unset_alias - function that sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
char *p = _strchr(str, '=');
if (!p)
return (1);
char c = *p;
*p = 0;
int ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_wit((info->alias, str, -1)));
*p = c;
return (ret);
}
/**
 * set_alias - function that sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
char *p = _strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - function that prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
if (!node)
return (1);
char *p = _strchr(node->str, '=');
for (char *a = node->str; a <= p; _putchar(*a++))
{
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
}
/**
 * _myalias - function that mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
if (info->argc == 1)
{
list_t *node = info->alias;

while ((node) print_alias(node), node = node->next)
return (0);
}
for (int i = 1; info->argv[i]; i++)
{
char *p = _strchr(info->argv[i], '=');
if (p)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
return (0);
}
}
