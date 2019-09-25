#ifndef __VIDEO_DECODER_INIT__
#define __VIDEO_DECODER_INIT__

#include "Decoder/Decoder.h"

#include <string>

class VideoDecoder : public Decoder
{
	private :
		std::string& executed_file_path;

	public :
		VideoDecoder(std::string& file_path) : executed_file_path(file_path) {}
		~VideoDecoder() { }

		void Decode();
};

#endif

