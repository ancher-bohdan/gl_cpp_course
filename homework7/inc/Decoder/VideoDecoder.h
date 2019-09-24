#ifndef __VIDEO_DECODER_INIT__
#define __VIDEO_DECODER_INIT__

#include "Decoder/Decoder.h"

class VideoDecoder : public Decoder
{
	public :
		VideoDecoder() = default;
		~VideoDecoder() { }

		void Decode();
}

#endif

