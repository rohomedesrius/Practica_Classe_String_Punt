
#ifndef __logClass_H__
#define __logClass_H__

#include <Windows.h>
#include <wtypes.h>
#include <stdio.h>

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

class logClass {

public:

	logClass();

	void log(const char file[], int line, const char* format, ...);

	~logClass();
};

#endif