#include <cstring>
#include <iostream>

#include "vintage_port.h"

#define DEFAULT_NICKNAME_SIZE	10

VintagePort::VintagePort() : Port()
{
	nickname = new char[DEFAULT_NICKNAME_SIZE]();
	year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) :
	Port(br, "vintage", b)
{
	nickname = new char[strlen(nn)];
	std::copy(nickname, nickname + strlen(nickname), nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp) :
	nickname(vp.nickname), year(vp.year), brand(vp.brand), bottles(vp.bottles) 
{
}

VintagePort& VintagePort::operator= (const VintagePort & vp)
{
	if(this != &vp)
	{
		if(strlen(nickname) != strlen(vp.nickname))
		{
			if(nickname != nullptr)
			{
				delete[] nickname;
				nickname = nullptr;
			}
			nickname = new char[strlen(vp.nickname)];
		}
		std::copy(vp.nickname, vp.nickname + strlen(vp.nickname), nickname);
		
		if(strlen(brand) != strlen(vp.brand))
		{
			if(brand != nullptr)
			{
				delete[] brand;
				brand = nullptr;
			}
			brand = new char[strlen(vp.brand)];
		}
		std::copy(vp.brand, vp.brand + strlen(vp.brand), brand);

		bottles = vp.bottles;
		year = vp.year;
	}
	return *this;
}

void VintagePort::Show() const
{
	std::cout << "NickName: " << nickname << std::endl;
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Kind: vintage" << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
	std::cout << "Year: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
	os << vp.nickname << ", " << vp.brand << ", vintage, " << vp.bottles << ", " << vp.year;
	return os;
}


