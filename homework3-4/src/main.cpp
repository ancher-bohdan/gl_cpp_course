#include "string_custom.h"

int main()
{
	custom_string first(""), second("");
	std::cout << "Enter first string(without spaces):" << std::endl;
	std::cin >> first;
	std::cout << "your string is: " << first << std::endl;
	std::cout << "Enter second string(without spaces):" << std::endl;
	std::cin >> second;
	std::cout << "your string is: " << second << std::endl << std::endl;

	std::cout << "Is your string are equal? ... " << ((first == second) ? "YES" : "NO") << std::endl;
	
	custom_string third = first + second;
	std::cout << "Concatinated string " << third << std::endl << std::endl;

	std::cout << "Length of this string are " << third.length() << std::endl << std::endl;

	std::cout << "I`ll append your perfect string with my garbage: " << third.append("@#$BlaBlaBla:(((") << std::endl;
	std::cout << "Check if my garbage is present?: " << ((third.substr("BlaBla") != -1) ? "Yep! It present" : "No. WTF???") << std::endl;

	std::cout << "My garbage are at " << third.substr("BlaBla") << " position" << std::endl << std::endl;

	std::cout << "HE HE HE!!!! Let me mess with your string a little bit more!!!!" << std::endl;

	third.insert("GARBAGE!!!!", 1).append(first).swap();

	std::cout << "Now your string is " << third << std::endl;

	return 0;
}
