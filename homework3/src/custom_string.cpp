#include "string_custom.h"
#include <cstring>

int custom_string::index_of(char ch)
{
	unsigned int result = 0;

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

custom_string& custom_string::append(const custom_string& str)
{
	if(str.strlen == 0)
		return *this;

	char *new_data = new char[this->strlen + str.strlen - 1];
	
	if(new_data == nullptr)
		return *this;

	if(this->data != nullptr)
	{
		std::copy(this->data, this->data + this->strlen - 1, new_data);
		if(this->data != str.data)
		{
			delete[] this->data;
			this->data = nullptr;
		}
	}

	std::copy(str.data, str.data + str.strlen, new_data + this->strlen - 1);

	this->strlen += (str.strlen - 1);
	this->data = new_data;

	return *this;
}

custom_string& custom_string::append(const char *str)
{
	custom_string *tmp = new custom_string(str);
	if(tmp == nullptr)
		return *this;

	return this->append(*tmp);
}

int custom_string::compare(const custom_string& str)
{
	int iterations = str.strlen > this->strlen ? this->strlen : str.strlen;
	for(int i = 0; i < iterations; i++)
	{
		if(this->data[i] > str.data[i])
		{
			return -1;
		}
		else if(this->data[i] < str.data[i])
		{
			return 1;
		}
		else
			continue;
	}
	return 0;
}

unsigned int custom_string::length()
{
	return this->strlen;
}

bool custom_string::resize(unsigned int length)
{
	char *new_str = new char[length];
	
	if(new_str == nullptr)
		return false;

	if(this->data != nullptr)
	{
		if(this->strlen > length)
		{
			std::copy(this->data, this->data + this->strlen, new_str);
		}
		else
		{
			std::copy(this->data, this->data + length - 1, new_str);
			new_str[length - 1] = '\0';
		}

		delete[] this->data;
		this->data = nullptr;
	}
	
	this->data = new_str;
	this->strlen = length;

	return true;
}

void custom_string::clear()
{
	if(this->data != nullptr)
	{
		memset(this->data, 0, this->strlen);
	}
}

int custom_string::substr(const char *str)
{
	unsigned int candidate = 0;
	unsigned int i, j = 0;
	for(i = 0; i < this->strlen; i++)
	{
		if((this->data[i]) == str[j])
		{
			candidate = i;
			while((str[j] != '\0') && (this->data[i] != '\0'))
			{
				if(str[++j] != (this->data[++i]))
				{
					break;
				}
			}
			if(str[j] == '\0')
				return candidate;
		}
	}

	return -1;
}

custom_string& custom_string::swap()
{
	if(this->data == nullptr)
		return *this;

	for(unsigned int i = 0; i <= ((strlen - 1) >> 1); i++ )
	{
		char tmp = data[i];
		data[i] = data[strlen - i - 2];
		data[strlen - i] = tmp;
	}

	return *this;
}

bool custom_string::operator==(const custom_string& str)
{
	return this->compare(str) == 0 ? true : false;
}

bool custom_string::operator!=(const custom_string& str)
{
	return this->compare(str) == 0 ? false : true;
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

custom_string custom_string::operator+(const custom_string& other)
{
	custom_string result("");
	result += (*this);
	result += other;
	return result;
}

std::ostream& operator<<(std::ostream& os, const custom_string& str)
{
	os << "[" << str.strlen << "]: " << str.data;
	return os;
}

std::istream& operator>>(std::istream& is, custom_string& str)
{
	char tmp[256];

	is >> tmp;

	custom_string d(tmp);

	str = d;

	return is;
}

