/**
 * Author:   SMC<smcdef@163.com>
 * Date:     2017-06-02
 * Describe: object
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef OBJECT_H
#define OBJECT_H

namespace smc_lib
{

class object
{
public:
	void* operator new (unsigned int size) throw();
	void operator delete (void *p) throw();
	void* operator new[] (unsigned int size) throw();
	void operator delete[] (void *p) throw();
	virtual ~object() = 0;
};

} // smc_libf

#endif // OBJECT_H
