
#ifndef __projString_H__
#define __projString_H__

class projString{

public:

	int p_len;
	char* p_string;

public:

	//Construcors
	projString();
	projString(const char*, ...);
	projString(const projString&);

	//Comparison
	bool operator== (const projString& p_str) const;
	bool operator== (const char* p_str) const;

	//Comparison
	bool operator!= (const projString& p_str)const;
	bool operator!= (const char* p_str)const;

	//PlusEqual Operator
	const projString& operator+= (const char*);
	const projString& operator+= (const projString&);

	//Attributor
	const projString& operator= (projString&);
	const projString& operator= (const char*);

	//Tools
	const int strLen()const;
	void strClear();
	void strAlloc(const unsigned int);
	const int strCapacity();
	const char* strGetString();

	//Destructor
	~projString();
};

#endif