/*
** EPITECH PROJECT, 2018
** bollinger
** File description:
** errormessage
*/

#include	<stdio.h>

void warning(short id)
{
	const char	*str[] = {
		"An integer expected as argument is invalid\0",
		"The file expected as argument is invalid\0",
		"The double expected as argument is invalid\0",
		"Invalid number of arguments\0",
		"An error occured while reading the given file\0",
		NULL
		};
	puts(str[id]);
	puts("Use  ./bollinger -h  for more informations\0");
}