#ifndef global_h
#define global_h
#include <math.h>
#include "klasa_prostokat.h"
#include "klasa_auto.h"
#include "klasa_boost.h"
const int glutWindowWidth = 800;
const int glutWindowHeight = 600;
const double M_PI = 3.14159265359;
const double PH_G = 0.6;
const double EPSILON = 0.00001;
//extern double R;
//extern double R2;

extern C_auto car;
//extern C_boost punkt;

void Draw_prostokat_kolor(double _a, double _b, double _red, double _green, double _blue);

#endif