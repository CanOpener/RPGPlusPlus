#include "stdafx.h"

class Vec
{
public :
	float x;
	float y;


	Vec(float X, float Y);
	void set(float X, float Y);

	inline float get_Magnitude() const;
	float get_Magnitude_Squared() const;

	Vec get_Parallel_Unit_Vector();

	Vec operator+ (Vec V);
	Vec operator+ (float N);

	Vec operator- (Vec V);
	Vec operator- (float N);

	Vec operator* (Vec V);
	Vec operator* (float N);

	Vec operator/ (Vec V);
	Vec operator/ (float N);
};