
#ifndef __point2D_H__
#define __point2D_H__

#include <windows.h>

class point2D{

public:

	float x, y;

public:

	void setZero();
	bool isZero()const;
	void negateVar();

	//+ & - operators
	point2D operator+(const point2D&)const;
	point2D operator-(const point2D&)const;

	//Increase & Decrease operators
	const point2D& operator+=(const point2D&);
	const point2D& operator-=(const point2D&);

	//Comparison
	bool operator==(const point2D&)const;
	bool operator!=(const point2D&)const;

	//Distance calculator
	const float distanceTo(point2D);
	//const float DistanceToAlternative(point2D, point2D);

};

#endif

