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

	delete str;

	std::cout << "End of program " << std::endl;

	return 0;
}
