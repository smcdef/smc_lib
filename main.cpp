#include <iostream>
#include "smart_pointer.h"
#include "exception_b.h"

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
	try {
		THROW_EXCEPTION(invalid_parameter_exception, "test");
	} catch (const invalid_parameter_exception& exp) {
		cout << exp.message() << endl;
		cout << exp.location() << endl;
	}

	return 0;
}