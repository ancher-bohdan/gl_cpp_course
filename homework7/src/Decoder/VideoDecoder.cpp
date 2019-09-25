#include "Decoder/VideoDecoder.h"

#include <cstdlib>
#include <cassert>

void VideoDecoder::Decode()
{
	const std::string play_command = "totem " + executed_file_path;

	int result = std::system(play_command.c_str());

	assert(result != 0);
}
