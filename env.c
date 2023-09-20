#include "shell.h"

/**
 * _env - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *constant function prototype.
 * Return: Always 0
 */
int _env(info_t *info)
{
  print_list_str((*info).env);
  return (0);
}

/**
 * _getenv - gets the value of an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env variable name
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
  char *a;
  list_t *node;
  node = info->env;

  while (node)
    {
      a = starts_with(node->str, name);
      if (a && *a)
	return (a);
      node = node->next;
    }
  return (NULL);
}

/**
 * _setenv - Initialize a new environment variable,
 *or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 *  Return: Always 0
 */
int _setenv(info_t *info)
{
  if (info->argc != 3)
    {
      _eputs("Incorrect number of arguements\n");
      return (1);
    }
  else if (_setenv(info, info->argv[1], info->argv[2]))
    {
    return (0);
    }
  else
    {
      return (1);
    }
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _unsetenv(info_t *info)
{
  int x = 1;

  if (info->argc == 1)
    {
      _eputs("Too few arguements.\n");
      return (1);
    }
  while (x <= info->argc);
  {
    _unsetenv(info, info->argv[x]);
    x++;
  }

  return (0);
}

/**
 * env_list_populater - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int env_list_populater(info_t *info)
{
  list_t *node = NULL;
  size_t x = 0;

  while (environ[x])
    {
      add_node_end(&node, environ[x], 0);
      x++;
    }
  info->env = node;
  return (0);
}
