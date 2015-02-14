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

bool intersection(point A, point B, point C, point D)
{
	if ((B.x>=C.x && D.x>=A.x && B.y>=C.y && D.y>=A.y) ||
		(
			((C.x-A.x)*(B.y-A.y)-(B.x-A.x)*(C.y-A.y))*((D.x-A.x)*(B.y-A.y)-(B.x-A.x)*(D.y-A.y)) <=0) ||
			(((A.x-C.x)*(D.y-C.y)-(D.x-C.x)*(A.y-C.y))*(B.x-C.x)*(D.y-C.y)-(D.x-C.x)*(B.y-C.y) <=0)
		)
	{
		return true;
	}
	return false;
}

bool belongs(point p, polygon& pol)
{
	int maxX = pol.points->d.x;
	int maxY = pol.points->d.y;
	polygon copy = pol;
	while (copy.points != NULL)
	{
		if (maxX < copy.points->d.x)
		{
			maxX = copy.points->d.x;
			maxY = copy.points->d.y;
		}
		copy.points = copy.points->next;
	}
	point maxPoint;
	maxPoint.x = maxX + 1;
	maxPoint.y = maxY;

	int count = 0;
	copy = pol;
	while (copy.points->next != NULL)
	{
		if (intersection(copy.points->d, copy.points->next->d, p, maxPoint))
		{
			count++;
		}
		copy.points = copy.points->next;
	}
	if (intersection(copy.points->d, pol.points->d, p, maxPoint))
	{
		count++;
	}
	if (count%2!=0)
	{
		return true;
	} else 
	{
		return false;
	}
}