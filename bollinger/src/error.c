/*
** EPITECH PROJECT, 2018
** bollinger
** File description:
** error
*/
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"bollinger.h"

static int isint(const char *str)
{
	int	i = 0;

	while (str && str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9') {
			warning(0);
			return (1);
		}
		++i;
	}
	return (0);
}

static int isfile(const char *file)
{
	int	ret = 0;

	if (access(file, F_OK) == -1 || access(file, R_OK) == -1) {
		warning(1);
		ret = -1;
	}
	return (ret);
}

static int isdouble(const char *str)
{
	int	i = 0;

	while (str && str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			if (str[i] != '.' && str[i] != '\n') {
				warning(2);
				return (1);
			}
		++i;
	}
	return (0);
}

int checkargs(char **av, t_args *data)
{
	int	ret = 0;

	if (isint(av[0]) == 1 || isdouble(av[1]) == 1 ||
		isfile(av[2]) == -1 || isint(av[3]) == 1)
		ret = 1;
	else {
		data->index = atoi(av[3]);
		data->period = atoi(av[0]);
		data->filename = strdup(av[2]);
		data->coef = atof(av[1]);
	}
	return (ret);
}