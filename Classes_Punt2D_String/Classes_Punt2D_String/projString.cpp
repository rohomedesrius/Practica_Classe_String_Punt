
#include <wtypes.h>
#include "projString.h"
#include "stdio.h"

//Constructors
projString::projString(){

	p_len = 1;
	p_string = new char[p_len];
	p_string[0] = '\0';
}

projString::projString(const char * p_str, ...)
{
	p_len = 0;
	if (p_str != NULL){

		static char tmp[4096];
		static va_list ap;

		va_start(ap, p_str);
		int res = vsprintf_s(tmp, 4096, p_str, ap);
		va_end(ap);

		if (res > 0)
		{
			strAlloc(res + 1);
			strcpy_s(p_string, p_len, tmp);
		}
	}

	if (p_len == 0){

		strAlloc(1);
		strClear();

	}
}

projString::projString(const projString& p_str){

	if (&p_str != NULL){

		strAlloc(p_str.strLen() + 1);
		strcpy_s(p_string, p_len, p_str.p_string);
	}
	else{

		strAlloc(1);
		strClear();
	}
}

// Operators
bool projString::operator== (const projString& p_str) const{

	return strcmp(p_str.p_string, p_string) == 0;

}
bool projString::operator== (const char* p_str) const{

	if (p_str != NULL)

		return strcmp(p_str, p_string) == 0;

	return false;

}

bool projString::operator!= (const projString& p_str) const{

	return strcmp(p_str.p_string, p_string) != 0;

}
bool projString::operator!= (const char* p_str) const{

	if (p_str != NULL)

		return strcmp(p_str, p_string) != 0;

	return true;
}

const projString& projString::operator= (projString& p_str){

	if (p_str.strLen() + 1 > p_len){

		delete[] p_string;
		strAlloc(p_str.strLen() + 1);

	}

	else

		strClear();

	strcpy_s(p_string, p_len, p_str.p_string);

	return(*this);

}
const projString& projString::operator= (const char* p_str)
{
	if (p_str != NULL)
	{
		if (strlen(p_str) + 1 > p_len)
		{
			delete[] p_string;
			strAlloc(strlen(p_str) + 1);
		}
		else
			strClear();
		strcpy_s(p_string, p_len, p_str);
	}
	else
	{
		strClear();
	}
	return(*this);
}

const projString& projString::operator+= (const projString& p_str){

	if (&p_str != NULL)
	{
		projString tmp_0;
		tmp_0 = p_string;

		int t_size = tmp_0.p_len + p_str.p_len;
		if (sizeof(p_string) <= t_size)
		{
			delete[]p_string;
			strAlloc(t_size + 1);
		}
		strcpy_s(p_string, t_size, tmp_0.p_string);

		strcat_s(p_string, t_size, p_str.p_string);
	}
	return (*this);

}
const projString& projString::operator+= (const char* p_str){
	if (&p_str != NULL)
	{
		projString tmp_0;
		tmp_0 = p_string;
	
		int t_size = tmp_0.p_len + strlen(p_str);
		if (sizeof(p_string) <= t_size) 
		{
			delete[]p_string;
			strAlloc(t_size + 1);
		}
		strcpy_s(p_string, t_size, tmp_0.p_string);

		strcat_s(p_string, t_size, p_str);
	}
	return (*this);
	/*
	if (p_str != NULL){

	strcat(p_string, strlen(p_str));
	return (*this);
	}

	else{
	return (*this);
	}*/
}

//Tools
const int projString::strLen()const {

	return p_len - 1;

}
void projString::strAlloc(const unsigned int a){

	p_string = new char[a];
	p_len = a;

}
void projString::strClear(){

	p_string[0] = '\0';
	p_len = 1;
}
const int projString::strCapacity(){

	return p_len;
}
const char* projString::strGetString(){

	return p_string;

}

//Destructor
projString::~projString()
{
	delete[]p_string;
}