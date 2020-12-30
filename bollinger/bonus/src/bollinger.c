/*
** EPITECH PROJECT, 2018
** bollinger
** File description:
** trade
*/

#include	<string.h>
#include	<stdlib.h>
#include	"bollinger.h"

int	main(int ac, char **av)
{
	int ret = 0;

	if (ac == 2 && strcmp(av[1], "-h\0") == 0) {
		usage();
	}
	else if (ac == 5) {
		ret = bollinger(av + 1);
	}
	else {
		warning(3);
		ret = 84;
	}
	return (ret);
}

int	bollinger(char **av)
{
	t_args	data;
	int	ret = 0;
	double	*values = NULL;

	if (checkargs(av, &data) == 1)
		ret = 84;
	if (ret != 84 && (values = fillprices(&data, values)) == NULL) //create a new filel
		ret = 84;
	if (ret != 84)
	{
		zbeul(&data, values);
		free(data.filename);
		free(values);
	}
	return (ret);
}