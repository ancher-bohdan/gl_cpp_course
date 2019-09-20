#ifndef __WINE__
#define __WINE__

#include <string>
#include <valarray>
#include <utility>


class Wine : private std::string, private std::pair<std::valarray<int>, std::valarray<int>>
{
	private:
		using ArrayIntT = std::valarray<int>;
		using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;
		
	public:
		Wine() = default;
		Wine(const char* label, int ny, const int yr[], const int bot[]) :
			std::string(label), PairArrayT(ArrayIntT(yr, ny), ArrayIntT(bot, ny)) {}
		Wine(const char* label, int ny) :
			std::string(label), PairArrayT(ArrayIntT(0, ny), ArrayIntT(0, ny)) {}
		~Wine() {}

		int getBottles(int year);
		void getBottles();
		std::string& label();
		int sum();
		void show();
};

#endif
