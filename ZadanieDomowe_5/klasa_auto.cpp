#include "klasa_auto.h"

using namespace std;

C_auto::C_auto(double _x, double _y, double _a, double _b, double  _angle, double _red, double _green, double _blue)
	: speed(0), acc(0), time(0), jedzie(0), przyspiesza(0)
{
	x = _x;
	y = _y;
	angle = _angle;
	a = _a;
	b = _b;

	red = _red;
	green = _green;
	blue = _blue;
}

void C_auto::Draw()
{
	glPushMatrix();
	glTranslated(x, y, 0);

	glPushMatrix();
	glRotated(-angle, 0, 0, 1);


	Draw_prostokat(); //karoseria


	

	glPopMatrix();
	glPopMatrix();
}

void C_auto::za_mapa(void)
{
	if (x < -3.5 || x> 3.5 || y>2.5 || y<-2.5)
	{
		x = 0;
		y = 0;
		speed = 0;
		angle = 0;
		time = 0;
		acc = 0;
	}
}

void C_auto:: zmien_predkosc()
{
	if (przyspiesza == 1) //przycisk wcisniety
	{
		time += 1;
		acc += 0.0001;
	}

	if (acc > 0 && przyspiesza == 0 && time>0) //przycisk zwolniony, pojazd jedzie sila bezwladnosci
	{
		time -= 1;
		acc -= 0.00003;
	}
	if (acc < 0 && przyspiesza == 0)
		acc = 0;


	speed = acc * time;

}