/**
 * Author:   SMC<smcdef@163.com>
 * Date:     2017-06-05
 * Describe: dynamic list
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

namespace smc_lib
{

template <typename T>
class dynamic_list : public sequ_list<T>
{
protected:
	int m_capacity;
public:
	dynamic_list(int capacity);
	void resize(int capacity);
	int capacity(void);
	~dynamic_list();
};

template <typename T>
dynamic_list<T>::dynamic_list(int capacity)
{
	this->m_array  = new T[capacity];
	this->m_length = 0;
	m_capacity     = capacity;
}

template <typename T>
void dynamic_list<T>::resize(int capacity)
{
	T* tmp = new T[capacity];

	if (tmp != NULL) {
		int len = capacity > this->m_length ? this->m_length : capacity;

		for (int i = 0; i < len; i++)
			tmp[i] = this->m_array[i];

		T *save        = this->m_array;
		this->m_array  = tmp;
		this->m_length = capacity;
		m_capacity     = capacity;

		delete[] save;
	} else {
		THROW_EXCEPTION(no_enough_memory_exception, "no enough memory for resize!");
	}
}

template <typename T>
int dynamic_list<T>::capacity(void)
{
	return m_capacity;
}

template <typename T>
dynamic_list<T>::~dynamic_list()
{
	delete[] this->m_array;
}


} // smc_lib

#endif // DYNAMIC_LIST_H
