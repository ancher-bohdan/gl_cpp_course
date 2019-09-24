#include "Decoder/AudioDecoder.h"

#include <cstdlib>
#include <cassert>

void AudioDecoder::Decode()
{
	const std::string play_command = "ffplay " + executed_file_path;

	int result = std::system(&play_command);

	assert(result != 0);

}
