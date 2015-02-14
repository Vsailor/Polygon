typedef struct elem* list;

struct point {
	int x;
	int y;
};

struct elem {
	point d;
	list next;
};

extern void setPoint(int x, int y, point& p);
extern list Init();
extern bool isEmpty(list l);
extern point Head(list l);
extern list Tail(list l);
extern list Add(list& l, point p);
extern void output(list l);