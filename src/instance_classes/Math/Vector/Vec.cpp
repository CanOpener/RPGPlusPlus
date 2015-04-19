#include "stdafx.h"

Vec::Vec(float X, float Y)
{
	set(X, Y);
}

void Vec::set(float X, float Y)
{
	x = X;
	y = Y;
}



float Vec::get_Magnitude_Squared() const
{
	return (x*x) + (y*y);
}

float Vec::get_Magnitude() const
{
	return sqrt(get_Magnitude_Squared());
}



Vec Vec::get_Parallel_Unit_Vector()
{
	return (*this / get_Magnitude());
}



Vec Vec::operator+ (Vec V)
{
	return Vec(x + V.x, y + V.y);
}

Vec Vec::operator+ (float N)
{
	return Vec(x + N, y + N);
}

Vec Vec::operator- (Vec V)
{
	return Vec(x - V.x, y - V.y);
}

Vec Vec::operator- (float N)
{
	return Vec(x - N, y - N);
}

Vec Vec::operator* (Vec V)
{
	return Vec(x * V.x, y * V.y);
}

Vec Vec::operator* (float N)
{
	return Vec(x * N, y * N);
}

Vec Vec::operator/ (Vec V)
{
	return Vec(x / V.x, y / V.y);
}

Vec Vec:: operator/ (float N)
{
	return Vec(x / N, y / N);
}
