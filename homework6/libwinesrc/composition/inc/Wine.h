#ifndef __WINE__
#define __WINE__

#include <string>
#include <valarray>
#include <utility>

class Wine
{
	private:
		using ArrayIntT = std::valarray<int>;
		using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;

		std::string *name;
		PairArrayT *pair;
	
	public:
		Wine() = default;
		Wine(const char* label, int ny, const int yr[], const int bot[]);
		Wine(const char* label, int ny);
		~Wine();

		int getBottles(int year);
		void getBottles();
		std::string label();
		int sum();
		void show();
};

#endif
