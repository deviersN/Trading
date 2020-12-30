//
// EPITECH PROJECT, 2018
// Trade
// File description:
// MarketPlace
//

#ifndef MARKET_HPP_
# define MARKET_HPP_

#include	<iostream>
#include	<fstream>
#include	<string>
#include	<unistd.h>
#include	"Mobil.hpp"

typedef struct Good_s {
	std::size_t	crypto;
	std::size_t	raw;
	std::size_t	stock;
	std::size_t	forex;
} Good_t;

typedef struct Mobile_s {
	Mobil	*crypto;
	Mobil	*raw;
	Mobil	*stock;
	Mobil	*forex;
} Mobile_t;

class MarketPlace
{
public:
        MarketPlace();
	~MarketPlace();
	void	setShares(Good_t shares);
	void	setMoney(float money);
	Good_t	getShares(void) const;
	float	getMoney(void) const;
	void    trader(std::string &value);
	void	manageCrypto(float unitPrice);
	void	manageRawMat(float unitPrice);
	void	manageForex(float unitPrice);
	void	manageStock(float unitPrice);
	void	updateStats(void);
	void	sellAll(void);
private:
	Good_t		_shares;
	Mobile_t	_average;
	float		_money;
};

#endif /* MARKET_HPP_ */
