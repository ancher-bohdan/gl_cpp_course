#ifndef __CUSTOM_STRING_INIT__
#define __CUSTOM_STRING_INIT__

#include <iostream>
#include <utility>

#define STRING_MAX_LENGTH	1024

class custom_string {
	private :
		char* data;
		unsigned int strlen;
	
	public :
		custom_string() = delete;
		
		custom_string(const char *input_text)
		{

			int size = 0;

			while( (input_text[size++] != '\0') && (size != STRING_MAX_LENGTH) );

			data = new char[size];

			for(int i = 0; i < size; i++)
			{
				data[i] = input_text[i];
			}

			strlen = size;
		}

		custom_string(const custom_string& input)
			: data(input.data), strlen(input.strlen) 
		{
		}

		custom_string(custom_string&& input)
			: data(std::exchange(input.data, nullptr)), strlen(std::exchange(input.strlen, 0))
		{
		}

		~custom_string()
		{
			if(data != nullptr)
			{
				delete[] data;
				data = nullptr;
			}
			strlen = 0;
		}

		bool operator==(const custom_string& str);
		bool operator!=(const custom_string& str);
		char operator[](size_t index);
		custom_string& operator=(const custom_string& other);
		custom_string& operator+=(const custom_string& other);
		custom_string operator+(const custom_string& other);
		friend std::istream& operator>>(std::istream& is, custom_string& str);
		friend std::ostream& operator<<(std::ostream& os, const custom_string& str);

		int index_of(char ch);
		int compare(const custom_string& str);
		unsigned int length();
		bool resize(unsigned int length);
		void clear();
		int substr(const char* str);
		custom_string& swap();
		custom_string& insert(const char* str, int position);
		custom_string& append(const char* str);
		custom_string& append(const custom_string& str);
};

#endif
