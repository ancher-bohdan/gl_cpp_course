#include "string_custom.h"

int main()
{
	custom_string *str = new custom_string("Hello world");

	custom_string copy(*str);

//	custom_string new_value = std::move(*str);

	int a =	str->index_of('e');

	std::cout << a << std::endl;
	
	std::cout << (*str == copy) << std::endl;

	copy.append(*str);

	copy.append("again");

	copy += (*str);

	custom_string first("Hello");
	custom_string second(" world");
	custom_string third = first + second;
	std::cout << third << std::endl;

	std::cout << "check substr: " << third.substr("ell") << std::endl;
	std::cout << "check swap: " << str->swap() << std::endl;

	std::cout << "Enter some string(without spaces):" << std::endl;
	std::cin >> third;
	std::cout << "Constructed string is: " << third << std::endl;


 
	delete str;

	std::cout << "End of program " << std::endl;

	return 0;
}
