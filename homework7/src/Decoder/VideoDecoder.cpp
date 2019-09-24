#include "Decoder/VideoDecoder.h"

#include <cstdlib>
#include <cassert>

void VideoDecoder::Decode()
{
	const std::string play_command = "totem " + executed_file_path;

	int result = std::system(&play_command);

	assert(result != 0);
}
