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

bool custom_string::append(const custom_string& str)
{
	char *new_data = new char[this->strlen + str.strlen];
	if(new_data == nullptr)
		return false;

	if(this->data != nullptr)
	{
		std::copy(this->data, this->data + this->strlen, new_data);
		delete[] this->data;
		this->data = nullptr;
	}

	std::copy(str.data, str.data + str.strlen, new_data + this->strlen);

	this->strlen += str.strlen;
	this->data = new_data;

	return true;
}

bool custom_string::append(const char *str)
{
	custom_string *tmp = new custom_string(str);
	if(tmp == nullptr)
		return false;

	return this->append(*tmp);
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

custom_string& custom_string::operator=(const custom_string& other)
{
	std::cout << "IN OVERLOADED ASSIGMEND OPERATOR" << std::endl;

	if(this != &other)
	{
		if(strlen != other.strlen)
		{
			if(data != nullptr)
			{
				delete[] data;
				data = nullptr;
			}
			strlen = 0;

			data = new char[other.strlen];
			strlen = other.strlen;
		}
		std::copy(other.data, other.data + other.strlen, data);
	}
	return *this;
}

custom_string& custom_string::operator+=(const custom_string& other)
{
	this->append(other);
	return *this;
}

