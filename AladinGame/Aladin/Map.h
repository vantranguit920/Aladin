#pragma once
#include "Viewport.h"
#include"TinyXML\tinyxml.h"

#include "TileSet.h"

#include "Object.h"
#include "Stage.h"



class Map
{
protected:

	int width, height, tileWidth, tileHeight;
	int _data[300][300];
	int numObjectGroups;

	TileSet* tileSet;
	

	D3DXVECTOR2 position;
	

public:

	std::vector<Stage*> listStage;

	Map();
	Map(Graphic* graphic);
	~Map();

	void ReadXML(Graphic* graphic, const char *path);
	int GetData(D3DXVECTOR2 pos);
	void SetData(D3DXVECTOR2 position, int data);

	void Update(float dt);
	void Render(Viewport * viewport);
};

