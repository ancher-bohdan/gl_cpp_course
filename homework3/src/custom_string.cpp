#include "string_custom.h"

int custom_string::index_of(char ch)
{
	int result = 0;

	std::cout << "Index of" << std::endl;

	for(; result < this->strlen; result++)
	{
		if(this->data[result] == ch)
		{
			return result;
		}
	}
	return -1;
}


bool custom_string::operator==(const custom_string& str)
{

	int iterations = str.strlen > this->strlen ? this->strlen : str.strlen;
	for(int i = 0; i < iterations; i++)
	{
		if((this->data[i] > str.data[i]) || (this->data[i] < str.data[i]))
		{
			return false;
		}
		else
			continue;
	}
	return true;
}

char custom_string::operator[](size_t index)
{
	return this->data[index];
}

