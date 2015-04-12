#ifndef klasa_auto_h
#define klasa_auto_h

#include "klasa_prostokat.h"

class C_auto : public C_prostokat
{
public:
	double acc;//acceleration
	int time;
	double speed;
	double angle;
	bool jedzie;
	bool przyspiesza;
	C_auto(double _x, double _y, double _a, double _b, double  _angle, double _red, double _green, double _blue);
		

	void Draw();

	/*
	void kolizja(C_prostokat sciana)
	{
	if ((V1.first || V2.first || V3.first || V4.first) > sciana.x -
	sciana.a / 2 && (V1.first || V2.first || V3.first || V4.first) <
	sciana.x + sciana.a / 2)
	{
	if ((V1.second || V2.second || V3.second || V4.second) > sciana.y -
	sciana.b / 2 && (V1.second || V2.second || V3.second || V4.second) <
	sciana.y + sciana.b / 2)
	{

	}
	}
	}
	*/

	void za_mapa(void);

	void zmien_predkosc();

};

#endif