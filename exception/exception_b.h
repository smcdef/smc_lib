/**
 * Author:   SMC<smcdef@163.com>
 * Date:     2017-05-31
 * Describe: exception_b
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef EXCEPTION_B_H
#define EXCEPTION_B_H
#include <cstdio>

namespace smc_lib
{

#define THROW_EXCEPTION(exp, mesg) (throw exp(mesg, __FILE__, __LINE__))

class exception_b
{
protected:
	char *m_mesg;
	char *m_location;
	void init(const char *mesg, const char *file, int line);
public:
	exception_b(const char *mesg);
	exception_b(const char *file, int line);
	exception_b(const char *mesg, const char *file, int line);
	exception_b(const exception_b& exp);
	exception_b& operator= (const exception_b& exp);
	virtual const char *message() const;
	virtual const char *location() const;
	virtual ~exception_b() = 0;
};

class arithmetic_exception : public exception_b
{
public:
	arithmetic_exception() : exception_b(NULL, NULL, 0) {}
	arithmetic_exception(const char *mesg) : exception_b(mesg, NULL, 0) {}
	arithmetic_exception(const char *file, int line) : exception_b(NULL, file, line) {}
	arithmetic_exception(const char *mesg, const char *file, int line) : exception_b(mesg, file, line) {}

	arithmetic_exception(const arithmetic_exception& exp) : exception_b(exp) {}
	arithmetic_exception& operator= (const arithmetic_exception& exp)
	{
		exception_b::operator=(exp);

		return *this;
	}
};

class null_pointer_exception : public exception_b
{
public:
	null_pointer_exception() : exception_b(NULL, NULL, 0) {}
	null_pointer_exception(const char *mesg) : exception_b(mesg, NULL, 0) {}
	null_pointer_exception(const char *file, int line) : exception_b(NULL, file, line) {}
	null_pointer_exception(const char *mesg, const char *file, int line) : exception_b(mesg, file, line) {}

	null_pointer_exception(const null_pointer_exception& exp) : exception_b(exp) {}
	null_pointer_exception& operator= (const null_pointer_exception& exp)
	{
		exception_b::operator=(exp);

		return *this;
	}
};

class index_out_bounds_exception : public exception_b
{
public:
	index_out_bounds_exception() : exception_b(NULL, NULL, 0) {}
	index_out_bounds_exception(const char *mesg) : exception_b(mesg, NULL, 0) {}
	index_out_bounds_exception(const char *file, int line) : exception_b(NULL, file, line) {}
	index_out_bounds_exception(const char *mesg, const char *file, int line) : exception_b(mesg, file, line) {}

	index_out_bounds_exception(const index_out_bounds_exception& exp) : exception_b(exp) {}
	index_out_bounds_exception& operator= (const index_out_bounds_exception& exp)
	{
		exception_b::operator=(exp);

		return *this;
	}
};

class no_enough_memory_exception : public exception_b
{
public:
	no_enough_memory_exception() : exception_b(NULL, NULL, 0) {}
	no_enough_memory_exception(const char *mesg) : exception_b(mesg, NULL, 0) {}
	no_enough_memory_exception(const char *file, int line) : exception_b(NULL, file, line) {}
	no_enough_memory_exception(const char *mesg, const char *file, int line) : exception_b(mesg, file, line) {}

	no_enough_memory_exception(const no_enough_memory_exception& exp) : exception_b(exp) {}
	no_enough_memory_exception& operator= (const no_enough_memory_exception& exp)
	{
		exception_b::operator=(exp);

		return *this;
	}
};

class invalid_parameter_exception : public exception_b
{
public:
	invalid_parameter_exception() : exception_b(NULL, NULL, 0) {}
	invalid_parameter_exception(const char *mesg) : exception_b(mesg, NULL, 0) {}
	invalid_parameter_exception(const char *file, int line) : exception_b(NULL, file, line) {}
	invalid_parameter_exception(const char *mesg, const char *file, int line) : exception_b(mesg, file, line) {}

	invalid_parameter_exception(const invalid_parameter_exception& exp) : exception_b(exp) {}
	invalid_parameter_exception& operator= (const invalid_parameter_exception& exp)
	{
		exception_b::operator=(exp);

		return *this;
	}
};

}
#endif // EXCEPTION_H
