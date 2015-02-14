#include "list.h"
#include <iostream>

using namespace std;


list Init() {
	return NULL;
}

bool isEmpty(list l) {
	if (l == NULL) {
		return true;
	}
	return false;
}


point Head(list l) {
	return l->d;
}


list Tail(list l) {
	return l->next;
}

list Add(list& l, point n) {
	list s = new elem;
	s->d.x = n.x;
	s->d.y = n.y;
	s->next = l;
	return s;
}

void output(list l) {
	while (!isEmpty(l)) {
		cout << "(" << l->d.x << "; " << l->d.y << ") ";
		l = l->next;
	}
}

void setPoint(int x, int y, point& p)
{
	p.x = x;
	p.y = y;
}