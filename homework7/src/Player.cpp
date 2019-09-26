#include "Decoder/Decoder.h"
#include "Player.h"


Player::Player(std::string& track) : track_list(1, track), is_played(false)
{
}

Player::Player(std::string tracks[], int nt) : track_list(tracks, tracks + nt), is_played(false)
{
}

void Player::play()
{
	if(!is_played)
	{
		is_played = true;
		for(std::string& song : track_list)
		{
			Decoder *d;

			d = parser.parse(song);
			d->Decode();

		}
	}
}

void Player::stop()
{
	is_played=false;
}
