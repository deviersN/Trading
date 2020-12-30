//
// EPITECH PROJECT, 2018
// Trade
// File description:
// main
//

#include	<iostream>
#include	<istream>
#include	<unistd.h>
#include	"MarketPlace.hpp"
#include	"Macro.hpp"

int	main()
{
	std::string     values = "";
	MarketPlace	*bolsa = new MarketPlace();
	clock_t		startTime = clock();
	clock_t		timePassed;
	double		secondsPassed = 0;

	while (getline(std::cin, values)) {
		timePassed = startTime - clock();
		secondsPassed = timePassed / (double)CLOCKS_PER_SEC;
		if(secondsPassed >= TIMER)
			break;
		bolsa->trader(values);
		usleep(PAUSE);
		bolsa->updateStats();
	}
	bolsa->sellAll();
	return 0;
}
