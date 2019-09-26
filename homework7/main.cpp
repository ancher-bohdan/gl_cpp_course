#include "Player.h"

#include <iostream>

int main()
{
	std::string songs[] = 
	{
		"../traks/TheVerveBittersweetSymphony.mp3",
		"../traks/file_example_MP4_480_1_5MG.mp4"
	};

	Player handle(songs, 2);

	handle.play();
}
