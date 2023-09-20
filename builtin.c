#include "shell.h"

/**
 * shellexit - exits the shell
 * @info: Structure containing potential arguments.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int shellexit(info_t *info)
{
	int check;

	if (info->argv[1])
	{
		check = _erratoi(info->argv[1]);
		if (check == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		else
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	else
	info->err_num = -1;
	return (-2);
}

/**
 * _cd - changes the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: 0 always
 */
int _cd(info_t *info)
{
	char *str, *dir, buffer[1024];
	int chdir_ret;

	str = getcwd(buffer, 1024);
	if (!str)
	  {
		_puts("No input\n");
	  }
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
		  chdir_ret = _getenv(info, "HOME=")
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = _getenv(info, "PWD=")
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * help - changes the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts(" my help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
