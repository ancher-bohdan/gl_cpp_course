#include "Wine.h"

#include <algorithm>
#include <iostream>
#include <cstring>

Wine::Wine(const char *label, int ny, const int yr[], const int bot[])
{
	name = new std::string(label);
	pair = new std::pair<std::valarray<int>, std::valarray<int>>(std::valarray<int>(yr, ny), std::valarray<int>(bot, ny));
}

Wine::Wine(const char *label, int ny)
{
	name = new std::string(label);
	pair = new std::pair<std::valarray<int>, std::valarray<int>>(std::valarray<int>(0, ny), std::valarray<int>(0, ny));
}

Wine::~Wine()
{
	delete [] name;
	delete pair;
}

std::string Wine::label()
{
	return *name;
}

int Wine::getBottles(int year)
{
	std::valarray<int> years = std::get<0>(*pair);
	std::valarray<int> bottles = std::get<1>(*pair);

	auto finded = std::find(std::begin(years), std::end(years), year);

	if(finded != std::end(years))
		return bottles[std::distance(std::begin(years), finded)];
	else
		return 0;


}

int Wine::sum()
{
	return std::get<1>(*pair).sum();
}

