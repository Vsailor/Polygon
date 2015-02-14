#include "Polygon.h"
#include <iostream>
using namespace std;

void main()
{
	point A,B,C;
	setPoint(1,5,A);
	setPoint(1,1,B);
	setPoint(5,1,C);
	polygon p;
	p.points = Init();
	p.points = Add(p.points, A);
	p.points = Add(p.points, B);
	p.points = Add(p.points, C);
	cout << S(p);
	system("pause");
}