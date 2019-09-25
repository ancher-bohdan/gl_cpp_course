#ifndef __DECODER_INIT__
#define __DECODER_INIT__

class Decoder
{
	public:
		Decoder() = default; 
		virtual ~Decoder() { }

		virtual void Decode() {}
};

#endif
