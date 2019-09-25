#ifndef __PLAYER_INIT__
#define __PLAYER_INIT__

#include <string>
#include <vector>

#include "Parser.h"

class Player
{
	private:
		std::vector<std::string> track_list;
		bool is_played;
		Parser parser;

	public:
		Player() = default;
		Player(std::string tracks[], int nt);
		Player(std::string& track);

		void play();
		void stop();
};

#endif
