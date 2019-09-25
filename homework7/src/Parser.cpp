#include "Parser.h"
#include "Decoder/AudioDecoder.h"
#include "Decoder/VideoDecoder.h"

Decoder* Parser::parse(std::string& path_to_file)
{
	size_t found = path_to_file.find_last_of('.');
	
	if(found != std::string::npos)
	{
		std::string extension = path_to_file.substr(found + 1);
		if(extension == "mp3")
		{
			return new AudioDecoder(path_to_file);
		}
		else if(extension == "mp4")
		{
			return new VideoDecoder(path_to_file);
		}
	}
	return nullptr;
}
