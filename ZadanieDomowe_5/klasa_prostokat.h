

#ifndef klasa_prostokat_h
#define klasa_prostokat_h

#include "freeglut_klawiatura.h"
#include <iostream>
#include <GL/freeglut.h>
#include <math.h>
#include <vector>
#include <utility>

class C_prostokat
{
public:
	double a, b;//wymiary
	double x, y;//polozenie
	double red, green, blue;
	/*
	pair < double, double > V1;
	pair < double, double > V2;
	pair < double, double > V3;
	pair < double, double > V4;
	*/
	C_prostokat(){};
	C_prostokat(double _x, double _y, double _a, double _b, double _red, double _green, double _blue);

	void Draw_prostokat();//rysuje prostokat tego koloru co obiekt (domyslny)
	virtual void Draw() = 0;
	

};

#endif