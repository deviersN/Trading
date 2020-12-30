/*
** EPITECH PROJECT, 2018
** bollinger
** File description:
** curses
*/

#include	<ncurses.h>
#include	"bollinger.h"

void displaybackground()
{
	mvprintw(0, 0, "+-------------------------------------------------");
	mvprintw(0, 50, "-------------------------------------------------+");
	mvprintw(19, 0, "+-------------------------------------------------");
	mvprintw(19, 50, "-------------------------------------------------+");
	mvprintw(23, 0, "+-------------------------------------------------");
	mvprintw(23, 50, "-------------------------------------------------+");
	for (int i = 1; i < 23; ++i)
	{
		mvprintw(i, 0, "|");
		mvprintw(i, 99, "|");
	}
}

void setupcurses(t_args *data, int max)
{
	initscr();
	start_color();
	noecho();
	curs_set(0);
	displaybackground(data, max);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	mvprintw(10, 98, "<+%d", max / 2);
	mvprintw(19, 98, "<+0");
	attron(COLOR_PAIR(3));
	mvprintw(24, 0, "- BANDE SUPERIEUR");
	attron(COLOR_PAIR(2));
	mvprintw(24, 20, "- MOYENNE MOBILE");
	attron(COLOR_PAIR(1));
	mvprintw(24, 40, "- BANDE INFERIEUR");
	attron(COLOR_PAIR(4));
	mvprintw(24, 60, "- COEF STANDARD");
	attron(COLOR_PAIR(5));
}

void	printdata(double y, int x, double max)
{
	static int	type = 0;

	type ++;
	attron(COLOR_PAIR(type % 4 + 1));
	mvprintw(19 - y / max * 20, 98 - x * 2, "*");
	attron(COLOR_PAIR(5));
}
