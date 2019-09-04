#include <csting>

Port::Port(const char* br = "none", const char* st = "none", int b = 0)
{
	brand = new char[strlen(br)];
	std::copy(br, br + strlen(br), brand);

	std::copy(st, st + strlen(st), style);
	if(b >= 0)
		bottles = b;
	else
		bottles = 0;
}

Port::Port(const Port& p) :
	brand(p.brand), bottles(p.bottles)
{
	int size = sizeof(p.style) / sizeof(p.style[0]);
	for(int i = 0; i < size; i++)
	{
		style[i] = p.style[i];
	}
}

Port& Port::operator= (const Port& p)
{
	if(this != &p)
	{
		if(strlen(brand) != strlen(p.brand))
		{
			if(brand != nullptr)
			{
				delete[] brand;
				brand = nullptr;
			}
			brand = new char[strlen(p.brand)];
		}

		std::copy(p.brand, p.brand + strlen(p.brand), brand);
		std::copy(p.style, p.style + (sizeof(p.style) / sizeof(p.style[0])), style);

		boottles = p.bottles;
	}
	return *this;
}

Port& Port::operator+= (int b)
{
	bottles += b;
	return *this;
}

Port& Port::operator-= (int b)
{
	if(bottles > 0)
		bottles -= b;
	return *this;
}

