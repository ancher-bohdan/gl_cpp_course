#include <iostream>
#include <string>

#include "header.h"

static operation_t operations[] =
{
	{
		.operation = '+',
		.func = add
	},
	{
		.operation = '-',
		.func = subtract
	},
	{
		.operation = '*',
		.func = multiply
	},
	{
		.operation = '/',
		.func = divide
	}
};

int main(int argv, char** args)
{
	
	if(argv !=  3)
	{
		std::cout << "Using: homework <first_number> <second_number>" << std::endl;
		return 0;
	}
	
	try
	{
		std::string first = args[1];
		std::string second = args[2];
		
		int a1 = std::stoi(first, nullptr, 10);
		int a2 = std::stoi(second, nullptr, 10);

		for(const auto& s : operations)
		{
			std::cout << a1 << " " << s.operation << " " << a2 << " = " << s.func(a1, a2) << std::endl;
		}
	
		set_bit(a1, 0, true);

		std::cout << "After function set_bit: " << a1 << std::endl;

	}
	catch(const std::invalid_argument& ia)
	{
		std::cout << "All arguments should be a number in decimal" << std::endl;
		std::cout <<  "Exception in function: " << ia.what() << std::endl;
		return 0;
	}

}
