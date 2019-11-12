#include "Cell.h"



Cell::Cell()
{
}

bool Cell::isContain(RECT r) 
{
	return !((x + CELL_WIDTH < r.left) || (x > r.right) || (y > r.bottom) || (y + CELL_HEIGHT < r.top));
}

Cell::Cell(int x,int y)
{
	this->x = x;
	this->y = y;
}
void Cell::addObject(MapObject* obj)
{
	if (obj != NULL && isContain(obj->getBound())) {
		listObject.insert(obj);
	}
}
void Cell::removeObject(MapObject* obj) {
	if (listObject.find(obj) != listObject.end()) {
		listObject.erase(obj);

	}
}

RECT Cell::GetCellBound()
{
	RECT r;
	r.left = x;
	r.top = y;
	r.right = r.left + CELL_WIDTH;
	r.bottom = r.top + CELL_HEIGHT;
	return r;
}

Cell::~Cell()
{
	listObject.erase(listObject.begin(), listObject.end());
}
