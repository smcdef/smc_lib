/**
 * Author:   SMC<smcdef@163.com>
 * Date:     2017-05-31
 * Describe: exception_b
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "exception_b.h"

using namespace std;

namespace smc_lib
{

void exception_b::init(const char *mesg, const char *file, int line)
{
	m_mesg = (char *)malloc(strlen(mesg) + 1);
	if (m_mesg != NULL)
		m_mesg = strcpy(m_mesg, mesg);
	else
		m_mesg = NULL;

	if (file != NULL) {
		char sl[16] = {0};

		sprintf(sl, "%d", line);
		m_location = (char *)malloc(sizeof(file) + sizeof(sl) + 2);
		if (m_location != NULL) {
			m_location = strcpy(m_location, file);
			m_location = strcat(m_location, ":");
			m_location = strcat(m_location, sl);
		} else {
			m_location = NULL;
		}

	} else {
		m_location = NULL;
	}
}

exception_b::exception_b(const char *mesg)
{
	init(mesg, NULL, 0);
}

exception_b::exception_b(const char *file, int line)
{
	init(NULL, file, line);
}

exception_b::exception_b(const char *mesg, const char *file, int line)
{
	init(mesg, file, line);
}

exception_b::exception_b(const exception_b& exp)
{
	m_mesg = exp.m_mesg;
	m_location = exp.m_location;
}

exception_b& exception_b::operator= (const exception_b& exp)
{
	if (this != &exp) {
		free(m_mesg);
		free(m_location);
		m_mesg = exp.m_mesg;
		m_location = exp.m_location;
	}

	return *this;
}

const char *exception_b::message() const
{
	return m_mesg;
}

const char *exception_b::location() const
{
	return m_location;
}

exception_b::~exception_b()
{
	free(m_mesg);
	free(m_location);
}

}
