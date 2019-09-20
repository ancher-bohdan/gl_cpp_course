#include "Wine.h"

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>

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
	delete name;
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

void Wine::getBottles()
{
	using std::cin;
	using std::cout;
	using std::endl;
	
	char input[50];
	size_t index = 0;
	memset(input, 0, 50);

	cout << "Write a year and number of bottles, separated by spaces.(For ex.: <year> <num_of_bottles>)" << endl;

	do
	{
		do
		{
			cout << " >>> ";
			cin.getline(input, 50);
		}while(input[0] == 0);

		char* token = strtok(input, " ");
		if(token == nullptr)
		{
			cout << "Wrong format! (Expected format: <year> <num_of_bottles>)" << endl;
			cout << "Please, enter " << (std::get<0>(*pair).size() - index) << " more pair of value " << endl;
			continue;
		}

		int year = atoi(token);
		if(!year)
		{
			cout << "Year {" << year << "} is not allowed here" << endl;
			cout << "Please, enter " << (std::get<0>(*pair).size() - index) << " more pair of value " << endl;
			continue;
		}
		
		token = strtok(nullptr, " ");
		if(token == nullptr)
		{
			cout << "Wrong format! (Expected format: <year> <num_of_bottles>)" << endl;
			cout << "Please, enter " << (std::get<0>(*pair).size() - index) << " more pair of value " << endl;
			cout << " >>> ";
			cin.getline(input, 50);
			continue;
		}

		int numofbottle = atoi(token);
		if(numofbottle < 0)
		{
			cout << "Num of bottle are {" << numofbottle << "}. Not allowed" << endl;
			cout << "Please, enter " << (std::get<0>(*pair).size() - index) << " more pair of value " << endl;
			continue;
		}

		cout << "your enter {" << year << ", " << numofbottle << "}. Saving..." << endl;

		std::get<0>(*pair)[index] = year;
		std::get<1>(*pair)[index] = numofbottle;
		index++;
		memset(input, 0, 50);

		cout << "SAVED! Please, enter " << (std::get<0>(*pair).size() - index) << " more pair of value " << endl;
	} while(index != std::get<0>(*pair).size());

	cout << endl;
}

int Wine::sum()
{
	return std::get<1>(*pair).sum();
}

void Wine::show()
{
	std::valarray<int> years = std::get<0>(*pair);
	std::valarray<int> bottles = std::get<1>(*pair);
	int index = 0;
	int *pindex = &index;

	std::cout << "Wine " << *name << "; there are " << years.size() << " number of record" << std::endl;
	std::cout << "We have: " << std::endl;

	std::for_each(std::begin(years), std::end(years), 
			[pindex, bottles](int &y) {std::cout << "{ " << y << ", " << bottles[(*pindex)++] << " }" << std::endl; });

	std::cout << std::endl;
}



