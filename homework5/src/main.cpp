#include "vintage_port.h"
#include <vector>

int main()
{
	Port p2("Gallo", "ruby", 50);
	VintagePort v2("Gallo", 10, "Delishious", 1956);
	VintagePort v1;
	Port p1;

	std::cout << "[p1]: " << p1 << std::endl;
	std::cout << "[v2]: " << v2 << std::endl;
	p1.Show();
	v2.Show();

	p1 = v2;

	std::cout << "[p1]: " << p1 << std::endl;
	std::cout << "[v2]: " << v2 << std::endl;
	p1.Show();
	v2.Show();
	/*
	VintagePort v1;
	VintagePort v2("Gallo", 10, "Delishious", 1956);
	VintagePort *v3 = new VintagePort("Twilight", 2, "Gorgeous", 1885);

	Port p1;
	Port p2("Gallo", "ruby", 50);
	Port *p3 = new Port("Hoeur", "tawny", 1);

	Port p4(p2);
	VintagePort v4(v2);

	/*
	std::cout << v1 << std::endl;
	std::cout << p1 << std::endl;

	std::cout << *p3 << std::endl;
	std::cout << *v3 << std::endl;

	std::cout << p2 << std::endl;
	std::cout << v2 << std::endl;

	v1.Show();
	std::cout << std::endl;
	v2.Show();
	std::cout << std::endl;
	v3->Show();
	std::cout << std::endl;

	p1.Show();
	std::cout << std::endl;
	p2.Show();
	std::cout << std::endl;
	p3->Show();
	std::cout << std::endl;

	delete p3;
	delete v3;
*/
	return 0;
 }
