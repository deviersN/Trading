//
// EPITECH PROJECT, 2018
// Trade
// File description:
// Mobil
//

#ifndef MOBIL_HPP_
# define MOBIL_HPP_

class Mobil
{
public:
	Mobil();
	~Mobil();
	float	getAverage();
	void	addValue(float val);
private:
	float	*_datas;
	float	_average;
};

#endif /* MOBIL_HPP_ */
