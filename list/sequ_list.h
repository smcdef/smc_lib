/**
 * Author:   SMC<smcdef@163.com>
 * Date:     ctrl+alt+d
 * Describe: sequence list
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef SEQU_LIST_H
#define SEQU_LIST_H

#include "list.h"
#include "exception_b.h"

namespace smc_lib
{

template <typename T>
class sequ_list : public list<T>
{
protected:
	T *m_array;
	int m_length;
public:
	bool insert(int index, const T& e);
	bool remove(int index);
	bool set(int index, const T& e);
	bool get(int index, T& e) const;
	int length() const;
	void clear();

	T& operator [] (int index);
	T operator [] (int index) const;

	virtual int capacity(void) = 0;
};

template <typename T>
bool sequ_list<T>::insert(int index, const T& e)
{
	bool ret = ((index >= 0) && (index <= m_length));
	ret = (ret && (m_length + 1) <= capacity());

	if (ret) {
		for (int pos = m_length; pos > index; --pos)
			m_array[pos] = m_array[pos - 1];
		m_array[index] = e;
		m_length++;
	}

	return ret;
}

template <typename T>
bool sequ_list<T>::remove(int index)
{
	bool ret = ((index >= 0) && (index < m_length));

	if (ret) {
		for (int pos = index; pos < m_length - 1; ++pos)
			m_array[pos] = m_array[pos + 1];
		m_length--;
	}

	return ret;
}

template <typename T>
bool sequ_list<T>::set(int index, const T& e)
{
	bool ret = ((index >= 0) && (index < m_length));

	if (ret)
		m_array[index] = e;

	return ret;
}

template <typename T>
bool sequ_list<T>::get(int index, T& e) const
{
	bool ret = ((index >= 0) && (index < m_length));

	if (ret)
		e = m_array[index];

	return ret;
}

template <typename T>
int sequ_list<T>::length() const
{
	return m_length;
}

template <typename T>
void sequ_list<T>::clear()
{
	m_length = 0;
}

template <typename T>
T& sequ_list<T>::operator [] (int index)
{
	if ((index >= 0) && (index < m_length))
		return m_array[index];
	else
		THROW_EXCEPTION(index_out_bounds_exception, "parameter index is invalid!");

}

template <typename T>
T sequ_list<T>::operator [] (int index) const
{
	return const_cast<sequ_list<T>&>(*this)[index];
}

} // smc_lib


#endif // SEQU_LIST_H
