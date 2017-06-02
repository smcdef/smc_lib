/**
 * Author:   SMC<smcdef@163.com>
 * Date:     2017-06-02
 * Describe: object
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include "object.h"
#include <cstdlib>

namespace smc_lib
{

void* object::operator new (unsigned int size) throw()
{
	return malloc(size);
}

void object::operator delete (void *p) throw()
{
	free(p);
}

void* object::operator new[] (unsigned int size) throw()
{
	return malloc(size);
}

void object::operator delete[] (void *p) throw()
{
	free(p);
}


object::~object()
{

}


} // smc_libf