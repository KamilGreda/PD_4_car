#ifndef klasa_boost_h
#define klasa_boost_h

#include "klasa_prostokat.h"
#include "klasa_auto.h"
#include "global.h"
class C_boost : public C_prostokat
{
public:
	C_boost(){};
	C_boost(double _x, double _y, double _a, double _b, double _red, double _green, double _blue);

	void Draw();
};

#endif