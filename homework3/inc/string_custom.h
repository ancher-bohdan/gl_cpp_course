#ifndef __CUSTOM_STRING_INIT__
#define __CUSTOM_STRING_INIT__

#include <iostream>
#include <utility>

#define STRING_MAX_LENGTH	1024

class custom_string {
	private :
		char* data;
		int strlen;
	
	public :
		custom_string() = delete;
		
		custom_string(const char *input_text)
		{

			int size = 0;

			std::cout << "IN CONSTRUCTOR" << std::endl;

			while( (input_text[size++] != '\0') && (size != STRING_MAX_LENGTH) );

			data = new char[size];

			for(int i = 0; i < size; i++)
			{
				data[i] = input_text[i];
			}

			strlen = size;
		}

		custom_string(const custom_string& input)
			: data(new char(*input.data)), strlen(input.strlen) 
		{
			std::cout << "IN COPY CONSTRUCTOR" << std::endl;
		}

		custom_string(custom_string&& input)
			: data(std::exchange(input.data, nullptr)), strlen(std::exchange(input.strlen, 0))
		{
			std::cout << "IN MOVE CONSTRUCTOR" << std::endl;
		}
};

#endif
