#pragma once
#include "MapObject.h"
#include<d3dx9.h>
#include <unordered_set>
#define CELL_WIDTH	250	
#define CELL_HEIGHT	250
class Cell
{
private:
	int x, y;
public:
	bool isContain(RECT r);
	std::unordered_set<MapObject*> listObject;
	Cell(int x, int y);
	void addObject(MapObject* obj);
	void removeObject(MapObject* obj);
	RECT GetCellBound();
	//Release memory
	void Release();
	Cell();
	~Cell();
};

