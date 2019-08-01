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

