/*
** EPITECH PROJECT, 2018
** bollinger
** File description:
** usage
*/

#include	<stdio.h>

void	usage(void)
{
	printf("Bollinger Bands\n\nUSAGE\n\t./bollinger [-h] period standard");
	printf("_dev indexes_files index_number\n\n\tperiod\t\tnumber of ");
	printf("indexes for the moving average\n\tstandard_dev\tstandard ");
	printf("deviation coefficient to apply\n\tindexes_files\tfile ");
	printf("containing daily indexes\n\tindex_number\tindex number to ");
	printf("compute moving average and Bollinger bands\n\nOPTIONS\n\t");
	printf("-h\t\tprint the usage and quit.\n");
}