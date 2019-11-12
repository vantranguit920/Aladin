#include "Map.h"
#pragma warning (disable : 4996)
Map::Map()
{
}

Map::Map(Graphic* graphic)
{
	ReadXML(graphic,"aladin.tmx");
	position = D3DXVECTOR2(0, 0);

	RECT r;
	r.left = 0;
	r.right = r.left + width * tileWidth;
	r.bottom = 0;
	r.top = r.bottom + height * tileHeight;

	if (r.right < r.top)
		r.right = r.top;
	else
		r.top = r.right;
	
}

Map::~Map()
{
	delete tileSet;
}

void Map::ReadXML(Graphic* graphic, const char *path)
{
	TiXmlDocument doc(path);
	if (!doc.LoadFile())
	{
		MessageBox(NULL, "Can't load Map xml file", "Error", MB_OK);
		return;
	}
	//map
	TiXmlElement* map = doc.RootElement();
	map->QueryIntAttribute("width", &width);
	map->QueryIntAttribute("height", &height);
	map->QueryIntAttribute("tilewidth", &tileWidth);
	map->QueryIntAttribute("tileheight", &tileHeight);

	//tileset
	TiXmlElement* tileset = map->FirstChildElement();
	tileSet = new TileSet(graphic, tileset);

	//layer
	TiXmlElement* layer = tileset->NextSiblingElement();

	//data
	TiXmlElement* data = layer->FirstChildElement();
	const char *dataText = data->GetText();

	//cắt chuỗi
	char *token;
	token = strtok((char *)(dataText), ",");
	int row = height - 1;
	int column = 0;
	while (token != NULL)
	{
		_data[row][column] = atoi(token);
		column++;
		if (column >= width)
		{
			row--;
			column = 0;
		}
		// strtok nhận vào NULL, để nó có thể tiếp tục tìm kiếm từ vị trí kết thúc trước đó.
		token = strtok(NULL, ",");
	}

}

void Map::Update(float dt)
{

}

int Map::GetData(D3DXVECTOR2 position)
{
	int w = position.x / tileWidth;
	int h = position.y / tileHeight;
	return _data[h][w];
}
void Map::SetData(D3DXVECTOR2 position, int data)
{
	int w = position.x / tileWidth;
	int h = position.y / tileHeight;
	_data[h][w] = data;
}

void Map::Render(Viewport * viewport)
{	
	for (int h = 0; h < 64; h++)
	{
		for (int w = 0; w < 248; w++)
		{
			int id = _data[h][w];
			if (id > 0)
			{
				D3DXVECTOR2 position(w*tileWidth, h*tileHeight);

				
				RECT objRECT;
				objRECT.left = position.x;
				objRECT.top = position.y;
				objRECT.right = objRECT.left + 32;
				objRECT.bottom = objRECT.top + 32;
				if (viewport->isContains(objRECT))
				{
					// Sửa chỗ này.
					//Chỉ vẽ những tileset nằm trong camera.

				}
				tileSet->Render(viewport, id, position);
				
				
			}
		}
	}
	
}
