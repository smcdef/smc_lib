/**
 * Author:   SMC<smcdef@163.com>
 * Date:     2017-05-31
 * Describe: smart pointer
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef SMART_POINTER_H
#define SMART_POINTER_H

namespace smc_lib
{

template <typename T>
class smart_pointer
{
	T* m_pointer;
public:
	smart_pointer(T *p = NULL);
	smart_pointer(const smart_pointer<T>& obj);
	smart_pointer<T>& operator = (const smart_pointer<T>& obj);
	T* operator -> ();
	T& operator * ();
	bool is_null();
	T* get_pointer();
	~smart_pointer();
};

template <typename T>
smart_pointer<T>::smart_pointer(T *p)
{
	m_pointer = p;
}

template <typename T>
smart_pointer<T>::smart_pointer(const smart_pointer<T>& obj)
{
	m_pointer = obj.m_pointer;
	const_cast<smart_pointer<T>&>(obj).m_pointer = NULL;
}

template <typename T>
smart_pointer<T>& smart_pointer<T>::operator = (const smart_pointer<T>& obj)
{
	if (this != &obj) {
		delete m_pointer;
		m_pointer = obj.m_pointer;
		const_cast<smart_pointer<T>&>(obj).m_pointer = NULL;
	}

	return *this;
}

template <typename T>
T* smart_pointer<T>::operator -> ()
{
	return m_pointer;
}

template <typename T>
T& smart_pointer<T>::operator * ()
{
	return *m_pointer;
}

template <typename T>
bool smart_pointer<T>::is_null()
{
	return m_pointer == NULL;
}

template <typename T>
T* smart_pointer<T>::get_pointer()
{
	return m_pointer;
}

template <typename T>
smart_pointer<T>::~smart_pointer()
{
	delete m_pointer;
}

}

#endif // SMART_POINTER_H
