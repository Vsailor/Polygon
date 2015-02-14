#include "List.h"

struct polygon
{
	list points;
};

extern void input(list points, polygon& p);
extern void output(polygon p);
extern double S(polygon& p);
extern bool belongs(point p, polygon& pol);
extern bool isConvex(polygon p);
