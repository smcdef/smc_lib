/**
 * Author:   SMC<smcdef@163.com>
 * Date:     2017-06-02
 * Describe: list
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef LIST_H
#define LIST_H

#include "object.h"

namespace smc_lib
{

template <typename T>
class list : public object
{
public:
	virtual bool insert(int index, const T& e) = 0;
	virtual bool remove(int index) = 0;
	virtual bool set(int index, const T& e) = 0;
	virtual bool get(int index, T& e) const = 0;
	virtual int length() const = 0;
	virtual void clear() = 0;
};

}

#endif // LIST_H
