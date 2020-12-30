//
// EPITECH PROJECT, 2018
// Trade
// File description:
// MarketPlace
//

#include	"MarketPlace.hpp"
#include	"Macro.hpp"

MarketPlace::MarketPlace()
{
	_shares = {0, 0, 0, 0};
	_average.crypto = new Mobil();
	_average.raw = new Mobil();
	_average.stock = new Mobil();
	_average.forex = new Mobil();
	_money = START_MONEY;
}

MarketPlace::~MarketPlace()
{
}

void	MarketPlace::setShares(Good_t shares)
{
	_shares = shares;
}

void	MarketPlace::setMoney(float money)
{
	_money = money;
}

Good_t	MarketPlace::getShares(void) const
{
	return _shares;
}

float	MarketPlace::getMoney(void) const
{
	return _money;
}

void	MarketPlace::trader(std::string &values)
{
	if (values.compare(0, 6, "crypto") == 0)
	        manageCrypto(stof(values.erase(0, 7)));
	else if (values.compare(0, 12, "raw_material") == 0)
		manageRawMat(stof(values.erase(0, 13)));
	else if (values.compare(0, 5, "forex") == 0)
		manageForex(stof(values.erase(0, 6)));
	else if (values.compare(0, 14, "stock_exchange") == 0)
		manageStock(stof(values.erase(0, 15)));
}

void	MarketPlace::manageCrypto(float unitPrice)
{
	_average.crypto->addValue(unitPrice);
	if (unitPrice < _average.crypto->getAverage() && _shares.crypto != 0)
		std::cout << SELL << _shares.crypto << GOOD_CR << std::endl;
	else if (unitPrice > _average.crypto->getAverage()
		&& _money > unitPrice) {
		std::cout << BUY << (int)(_money / unitPrice)
		<< GOOD_CR << std::endl;
	}
}

void	MarketPlace::manageRawMat(float unitPrice)
{
	_average.raw->addValue(unitPrice);
	if (unitPrice < _average.raw->getAverage() && _shares.raw != 0)
		std::cout << SELL << _shares.raw
		<< GOOD_RM << std::endl;
	else if (unitPrice > _average.raw->getAverage()
		&& _money > unitPrice) {
		std::cout << BUY << (int)(_money / unitPrice)
		<< GOOD_RM << std::endl;
	}
}

void	MarketPlace::manageForex(float unitPrice)
{
	_average.forex->addValue(unitPrice);
//	std::cout << "STATS" << std::endl;
/*	if (unitPrice > _average.forex->getAverage() && _shares.forex != 0)
		std::cout << SELL << _shares.forex << GOOD_FO << std::endl;
	else if (unitPrice < _average.forex->getAverage()
		&& _money > unitPrice) {
		std::cout << BUY << (int)((_money / unitPrice) / 3)
		<< GOOD_FO << std::endl;
		}*/
}

void	MarketPlace::manageStock(float unitPrice)
{
	_average.stock->addValue(unitPrice);
	if (unitPrice < _average.stock->getAverage() && _shares.stock != 0)
		std::cout << SELL << _shares.stock
		<< GOOD_SE << std::endl;
	else if (unitPrice > _average.stock->getAverage()
		&& _money > unitPrice) {
		std::cout << BUY << (int)(_money / unitPrice)
		<< GOOD_SE << std::endl;
	}
}

void	MarketPlace::updateStats()
{
	std::string	line;
	std::ifstream	infile;
	std::size_t	nbr = 6;

	infile.open (GENERAL_DATAS);
	while (!infile.eof()) {
		getline(infile, line);
		if (nbr > 5 && line.compare(0, 6, "crypto") == 0)
			_shares.crypto = std::stof(line.erase(0, 7));
		else if (nbr > 5 && line.compare(0, 12, "raw_material") == 0)
			_shares.raw = std::stof(line.erase(0, 13));
		else if (nbr > 5 && line.compare(0, 5, "forex") == 0)
			_shares.forex = std::stof(line.erase(0, 6));
		else if (nbr > 5 && line.compare(0, 14, "stock_exchange") == 0)
			_shares.stock = std::stof(line.erase(0, 15));
		else if (nbr > 5 && line.compare(0, 13, "current_money") == 0)
			_money = std::stof(line.erase(0, 14));
	}
	infile.close();
}

void	MarketPlace::sellAll(void)
{
	std::string security = "";
	std::cout << "SELL:" << _shares.crypto << ":crypto" << std::endl;
	getline(std::cin, security);
	std::cout << "SELL:" << _shares.raw << ":raw_material" << std::endl;
	getline(std::cin, security);
	std::cout << "SELL:" << _shares.forex << ":forex" << std::endl;
	getline(std::cin, security);
	std::cout << "SELL:" << _shares.stock << ":stock_exchange" << std::endl;
	getline(std::cin, security);
	usleep(PAUSE);
	std::cout << "EXIT" << std::endl;
}
