#include "Player.h"

#include <iostream>

int main()
{
	std::string song("../traks/TheVerveBittersweetSymphony.mp3");

	Player handle(song);

	handle.play();
}
