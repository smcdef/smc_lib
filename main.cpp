#include <iostream>
#include "smart_pointer.h"
#include "exception_b.h"
#include "static_list.h"
#include "dynamic_list.h"

using namespace std;
using namespace smc_lib;


class test
{
public:
	test(int i = 0)
	{
		cout << "test()" << ":" << i << endl;
	}

	~test()
	{
		cout << "~test()" << endl;
	}

	void print(void)
	{
		cout << "print" << endl;
	}
};

int main(int argc, char const *argv[])
{
	dynamic_list<int> l(5);
 
 	for (int i = 0; i < l.capacity(); i++)
 		l.insert(0, i);

 	for (int i = 0; i < l.length(); i++)
 		cout << l[i] << endl;

 	try {
 		l[5] = 1;
 	}
 	catch(const exception_b& e) {
 		cout << e.location() << endl;
 		cout << e.message() << endl;
 	}

 	l.resize(6);

 	try {
 		l[5] = 1;
 	}
 	catch(const exception_b& e) {
 		cout << e.location() << endl;
 		cout << e.message() << endl;
 	}

 	for (int i = 0; i < l.length(); i++)
 		cout << l[i] << endl;

	return 0;
}