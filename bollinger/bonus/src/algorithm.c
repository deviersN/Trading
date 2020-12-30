/*
** EPITECH PROJECT, 2018
** bollinger
** File description:
** algorithm
*/

#include	<math.h>
#include	<stdio.h>
#include	<ncurses.h>
#include	"bollinger.h"

double	maxvalue(double *values)
{
	double	ret = 0;

	for (int i = 0; values[i] != -1; i++) {
		if (values[i] > ret)
			ret = values[i];
	}
	return (ret);
}

void	algorithm(t_args *data, double *values, int end)
{
	double	somme = 0, somme2 = 0, MA = 0, SD = 0, Bp = 0, Bm = 0;
	int max = maxvalue(values) * 2;
	static int	u = 0;

	for (int i = 0; values[i] != -1 && i < end; i++) {
		if (i > end - data->period && i <= end) {
			somme += values[i];
			somme2 += (values[i] * values[i]);
			MA = somme / end;
//			mvprintw(25 + u, 0, "MA: %.2f", MA);
			SD = sqrt(somme2 / end - MA * MA);
			Bp = MA + data->coef * SD;
			Bm = MA - data->coef * SD;
		}
	}

	printdata(MA, u, max);
	printdata(Bp, u, max);
	printdata(SD, u, max);
	printdata(Bm, u++, max);
}

void	zbeul(t_args *data, double *values)
{
	int	i = 0;
	int	todo = 0;
	int	max = maxvalue(values) * 2;

	setupcurses(data, max);
	while (values[i] != -1)
		++i;
	todo = i - data->index;
	while (i > 0 && i > todo)
	{
		algorithm(data, values, i);
		--i;
	}
	getch();
	endwin();
}

/*	mvprintw(21, 0, "INPUT\nIndex: %d Period: %d SD_coef: %.2f", data->index,
		data->period, data->coef);
	mvprintw(23, 0, "OUTPUT\nMA: %.2f SD: %.2f B+: %.2f B-: %.2f",
		MA, SD, Bp, Bm);*/

/*
	get biggest price of values
	coord Y: height=value/20      --20 etant le nombre de lignes du tableau
	coord X: avance de sur/nb de points a chaque value
	mvprintw aux bonnes coordonnées
*/