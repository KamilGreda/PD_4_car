
#include "klasa_prostokat.h"

using namespace std;


 C_prostokat::C_prostokat(double _x, double _y, double _a, double _b, double _red, double _green, double _blue)
	{
		x = _x;
		y = _y;
		a = _a;
		b = _b;
		red = _red;
		green = _green;
		blue = _blue;

		//pozycje wierzocholkow
		/*
		V1.first = x + a / 2;
		V1.second = y + b / 2;

		V2.first = x + a / 2;
		V2.second = y - b / 2;

		V3.first = x - a / 2;
		V3.second = y + b / 2;

		V4.first = x - a / 2;
		V4.second = y - b / 2;
		*/
	}


 void C_prostokat::Draw_prostokat()
	{
		
		glColor3d(red, green, blue);

		glBegin(GL_POLYGON);
		{

			glVertex3d(a / 2, b / 2, 0);
			glVertex3d(a / 2, -b / 2, 0);
			glVertex3d(-a / 2, -b / 2, 0);
			glVertex3d(-a / 2, b / 2, 0);

		}
		glEnd();

	}
 