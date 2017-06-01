#include <iostream>
#include "smart_pointer.h"
//#include "exception.h"

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
	smart_pointer<test> ptr = new test(100);

	ptr->print();
	return 0;
}