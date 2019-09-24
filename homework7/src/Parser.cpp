#include "Parser.h"

Decoder Parser::parse(std::string& path_to_file)
{
	size_t found = path_to_file.find_last_of('.');
	
	if(found != string::npos)
	{
		std::string expension = path_to_file.substr(found + 1);
		if(expension == "mp3")
		{
			return AudioDecoder(path_to_file);
		}
		else if(extension == "mp4")
		{
			return VideoDecoder(path_to_file);
		}
	}
}
