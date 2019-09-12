#include "Wine.h"

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
