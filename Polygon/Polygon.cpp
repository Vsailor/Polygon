#include "Polygon.h"
#include <math.h>
#define NULL 0
#include <iostream>
using namespace std;


void input(list points, polygon& p)
{
	p.points = points;
}

void output(polygon p)
{
	output(p.points);
}

double S(polygon& p)
{
	point start = p.points->d;
  	double sum = 0;
	while(p.points->next!=NULL)
	{
		sum += p.points->d.x*p.points->next->d.y - p.points->next->d.x*p.points->d.y;
		p.points = p.points->next;
	}
	sum += p.points->d.x*start.y-start.x*p.points->d.y;
	return abs(sum/2.0);
}