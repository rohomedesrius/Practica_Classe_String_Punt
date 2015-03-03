
#include "point2D.h"
#include "math.h"

void point2D::setZero(){

	x = y = 0.0f;

}

bool point2D::isZero()const{

	return x == 0.0f && y == 0.0f;

}

void point2D::negateVar(){

	x = -x;
	y = -y;

}

point2D point2D::operator+(const point2D& a)const{

	point2D tmp;

	tmp.x = x + a.x;
	tmp.y = y + a.y;

	return tmp;
}

point2D point2D::operator-(const point2D& a)const{

	point2D tmp;

	tmp.x = x - a.x;
	tmp.y = y - a.y;

	return tmp;
}

const point2D& point2D::operator+=(const point2D& a){

	x += a.x;
	y += a.y;

	return(*this);
}

const point2D& point2D::operator-=(const point2D& a){

	x -= a.x;
	y -= a.y;

	return(*this);
}

bool point2D::operator==(const point2D& a) const{
	return (x == a.x && y == a.y);
}

bool point2D::operator!=(const point2D& a) const{
	return (x != a.x && y != a.y);
}

const float point2D::distanceTo(point2D tmp_1){

	float a = 0, b = 0, d = 0;

	a = (tmp_1.x - x) * (tmp_1.x - x);
	b = (tmp_1.y - y) * (tmp_1.y - y);

	d = fabsf(sqrt(a + b));

	return d;
};

/*
const float point2D::distanceToAlternative(point2D tmp_1, point2D tmp_2){

float a = 0, b = 0, d = 0;

a = (tmp_1.x - tmp_2.x) * (tmp_1.x - tmp_2.x);
b = (tmp_1.y - tmp_2.y) * (tmp_1.y - tmp_2.y);

d = fabsf(sqrt(a + b));

return d;
};
*/


