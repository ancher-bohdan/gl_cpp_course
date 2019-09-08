#include "vintage_port.h"
#include <vector>

int main()
{

	std::cout << "********* Assignment operator test *********" << std::endl;
	Port pp2("Gallo", "ruby", 50);
	VintagePort vv2("Gallo", 10, "Delishious", 1956);
	VintagePort vv1;
	Port pp1;

	std::cout << "[p1]: " << pp1 << std::endl;
	std::cout << "[v2]: " << vv2 << std::endl;
	pp1.Show();
	vv2.Show();

	pp1 = vv2;

	std::cout << "[p1]: " << pp1 << std::endl;
	std::cout << "[v2]: " << vv2 << std::endl;
	pp1.Show();
	vv2.Show();
	std::cout << "********************************************" << std::endl << std::endl;

	std::cout << "********* Call Show function *********" << std::endl;
	std::vector<Port*> *db = new std::vector<Port*>();
	db->push_back(new VintagePort("Gallo", 10, "Delishious", 1758));
	db->push_back(new Port("Gallo", "ruby", 50));
	db->push_back(new VintagePort());
	db->push_back(new Port());
	db->push_back(new VintagePort("Twilight", 2, "Gorgeous", 2012));
	db->push_back(new Port("Hoeur", "tawny", 1));

	for(Port *i : *db)
	{
		i->Show();
		delete i;
		std::cout << std::endl << std::endl;
	}

	delete db;
	std::cout << "********************************************" << std::endl << std::endl;


	std::cout << "********* Exaple of other functions *********" << std::endl;
	VintagePort v1;
	VintagePort v2("Gallo", 10, "Delishious", 1956);
	VintagePort *v3 = new VintagePort("Twilight", 2, "Gorgeous", 1885);

	Port p1;
	Port p2("Gallo", "ruby", 50);
	Port *p3 = new Port("Hoeur", "tawny", 1);

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

	p2 += 2;
	v2 += 3;
	std::cout << p2 << std::endl;
	std::cout << v2 << std::endl << std::endl;

	p2.Show();
	v2.Show();

	delete p3;
	delete v3;
	std::cout << "********************************************" << std::endl << std::endl;

	return 0;
 }
