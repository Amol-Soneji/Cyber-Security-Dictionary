#ifndef INTERNAL_PROGRAM_EXCEPTION_H
#define INTERNAL_PROGRAM_EXCEPTION_H

#include <exception>

using std::exception;

class InternalProgramException : public exception
{
	public:
		const char* what();
};

#endif // !INTERNAL_PROGRAM_EXCEPTION_H
