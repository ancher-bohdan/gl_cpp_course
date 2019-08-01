#include "string_custom.h"

int main()
{
	custom_string *str = new custom_string("Hello world");

	custom_string copy(*str);

	custom_string new_value = std::move(*str);

	int a =	new_value.index_of('e');

	std::cout << a << std::endl;

	delete[] str;

	std::cout << "End of program " << std::endl;

	return 0;
}
