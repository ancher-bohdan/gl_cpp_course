#include <bitset>
#include <iostream>
#include <climits>

void set_bit(int& value, size_t bitNumber, bool enabled)
{
	unsigned long result = 0;
	std::bitset<64> tmp(value);

	std::cout << "Initial value: " << tmp << std::endl;

	tmp = tmp.set(bitNumber, enabled);

	std::cout << "Changed value: " << tmp << std::endl;

	result = tmp.to_ulong();

	if(result <= UINT_MAX)
	{
		value = (int)result;
	}
	else
	{
		throw "BUG in function set_bit";
	}
}

int add(int first, int second)
{
	return first + second;
}

int divide(int first, int second)
{
	return (int)(first / second);
}

int multiply(int first, int second)
{
	return first * second;
}

int subtract(int first, int second)
{
	return first - second;
}

