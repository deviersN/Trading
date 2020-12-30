/*
** EPITECH PROJECT, 2018
** bollinger
** File description:
** cpp
*/

#ifndef BOLL_H_
# define BOLL_H_

typedef struct	s_args
{
	int	index;
	int	period;
	char	*filename;
	double	coef;
}		t_args;

/* bollinger */
int	bollinger(char **av);

/* usage.c */
void	usage(void);

/* error */
int	checkargs(char **av, t_args *data);

/* errormessage */
void	warning(short id);

/* getvalues.c */
double	*fillprices(t_args *data, double *value);

/* algorithm */
void	zbeul(t_args *data, double *values);

/* curses */
void	setupcurses();
void	printdata(double y, int x, double max);
void	printSD(double y, int x, double max);

#endif /* BOLL_H_ */
