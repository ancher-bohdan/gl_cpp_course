#ifndef __AUDIO_DECODER_INIT__
#define __AUDIO_DECODER_INIT__

#include "Decoder/Decoder.h"

#include <string>

class AudioDecoder : public Decoder
{
	private:
		std::string& executed_file_path;

	public:
		AudioDecoder(std::string& file_path) : executed_file_path(file_path) {}
		~AudioDecoder() {} 

		void Decode();
}

#endif
