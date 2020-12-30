/*
** EPITECH PROJECT, 2018
** bollinger
** File description:
** algorithm
*/

#include	<math.h>
#include	<stdio.h>
#include	"bollinger.h"

void algorithm(t_args *data, double *values)
{
	double	somme = 0, somme2 = 0, MA = 0, SD = 0, Bp = 0, Bm = 0;

	for (int i = 0; values[i] != -1; i++) {
		if (i > data->index - data->period && i <= data->index) {
			somme += values[i];
			somme2 += (values[i] * values[i]);
		}
	}
	MA = somme / data->period;
	SD = sqrt(somme2 / data->period - MA * MA);
	Bp = MA + data->coef * SD;
	Bm = MA - data->coef * SD;
	printf("INPUT\nIndex: %d\nPeriod: %d\nSD_coef: %.2f\n\n", data->index,
		data->period, data->coef);
	printf("OUTPUT\nMA: %.2f\nSD: %.2f\nB+: %.2f\nB-: %.2f\n",
		MA, SD, Bp, Bm);
}
