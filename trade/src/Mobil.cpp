//
// EPITECH PROJECT, 2018
// Trade
// File description:
// Mobil
//

#include	"Mobil.hpp"
#include	<algorithm>

Mobil::Mobil()
{
	_datas = new float[20];
	std::fill_n(_datas, 20, -1);
}

Mobil::~Mobil()
{
}

float	Mobil::getAverage()
{
	return _average;
}

/*
** Adds a new value to the stored datas and computes the new average mobile
*/
void	Mobil::addValue(float val)
{
	static std::size_t	it = 0;
	int divisor = 0;

	if (it == 20)
		it = 0;
	_datas[it] = val;
	it += 1;
	_average = 0;
	for (int i = 0; i < 20; i++) {
		if (_datas[i] != -1) {
			divisor += 1;
			_average += _datas[i];
		}
	}
	_average = (_average == 0 ? 0 : _average / divisor);
}
