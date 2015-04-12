#include "global.h"

using namespace std;

//double R = sqrt(pow(0.2 / 2, 2) + pow(0.3 / 2, 2));
//double R2 = ((0.2 / 2) / R)* (0.3 / 2);
C_auto car(0, 0, 0.2, 0.3, 0, 1, 0, 0);
//C_boost punkt(0, 0, 0.1, 0.1, 0, 0, 1);

void Draw_prostokat_kolor(double _a, double _b, double _red, double _green, double _blue)
{

	glColor3d(_red, _green, _blue);

	glBegin(GL_POLYGON);
	{

		glVertex3d(_a / 2, _b / 2, 0);
		glVertex3d(_a / 2, -_b / 2, 0);
		glVertex3d(-_a / 2, -_b / 2, 0);
		glVertex3d(-_a / 2, _b / 2, 0);

	}
	glEnd();

}