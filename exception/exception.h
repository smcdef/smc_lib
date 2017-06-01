/**
 * Author:   SMC<smcdef@163.com>
 * Date:     2017-05-31
 * Describe: exception
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <cstring>

namespace smc_lib
{

template <typename T>
class exception
{
protected:
	char *m_mesg;
	char *m_location;
public:
	exception(const char *mesg);
	exception(const char *file, const char *line);
	exception(const char *mesg, const char *file, const char *line);
	exception(const exception& exp);
	exception& operator= (exception& exp);
	virtual const char *message() const;
	virtual const char *location() const;
	virtual ~exception();
};

}

#endif // EXCEPTION_H
