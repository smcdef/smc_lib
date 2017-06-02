#include <iostream>
#include "smart_pointer.h"
#include "exception_b.h"
#include "object.h"

using namespace std;
using namespace smc_lib;


class test : public object
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
	object *obj1 = new test;

	delete obj1;

	return 0;
}