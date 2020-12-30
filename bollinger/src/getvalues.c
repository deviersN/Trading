/*
** EPITECH PROJECT, 2018
** bollinger
** File description:
** getvalues
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"bollinger.h"

static int isdouble(const char *str)
{
	int	i = 0;

	while (str && str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] != '.' && str[i] != '\n' && str[i] != 13) {
				return (1);
			}
		}
		++i;
	}
	return (0);
}

int countlines(t_args *data)
{
	int	ret = 0;
	FILE	*stream;
	char	*line = NULL;
	size_t	len = 0;

	stream = fopen(data->filename, "r");
	if (stream == NULL)
	{
		warning(4);
		ret = -1;
	}
	while (ret != -1 && getline(&line, &len, stream) > 0)
	{
		if (line != NULL && isdouble(line) == 0)
			ret += 1;
	}
	fclose(stream);
	free(line);
	return (ret);
}

int getvalues(t_args *data, double *value)
{
	int	ret = 0;
	int	i = 0;
	FILE	*stream;
	char	*line = NULL;
	size_t	len = 0;

	stream = fopen(data->filename, "r");
	if (stream == NULL)
		ret = 84;
	while (ret != 84 && getline(&line, &len, stream) > 0) {
		if (line != NULL && isdouble(line) == 0) {
			value[i] = atof(line);
			++i;
		}
	}
	value[i] = -1;
	fclose(stream);
	free(line);
	return (ret);
}

double *fillprices(t_args *data, double *values)
{
	int	ret = 0;

	ret = countlines(data);
	values = malloc(sizeof(double) * (ret + 1));
	if (ret <= 0 || values == NULL) {
		ret = 84;
	}
	else {
		ret = getvalues(data, values);
	}
	if (ret == 84)
		values = NULL;

	return (values);
}