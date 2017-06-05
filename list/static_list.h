/**
 * Author:   SMC<smcdef@163.com>
 * Date:     2017-06-05
 * Describe: static list
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "sequ_list.h"

namespace smc_lib
{

template <typename T, int N>
class static_list : public sequ_list<T>
{
protected:
	T m_space[N];
public:
	static_list()
	{
		this->m_array  = m_space;
		this->m_length = 0;
	}

	int capacity(void)
	{
		return N;
	}
};

}

#endif // STATIC_LIST_H
