#include "InternalProgramException.h"

const char* InternalProgramException::what()
{
	return "There was an internal program error.  \n  Program will close in 10 seconds.  ";
}