#pragma once
#include "Graphic.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Text.h"
#include "Viewport.h"
#include "Aladdin.h"
#include "Map.h"


class ObjectManager
{
protected:
	Aladdin *aladin;
	Viewport *viewport;
	//aladin
	Sound *sound;
	GSound *soundGame;
	Map *map;

	Sprite *spriteAladdin;
	SpriteSheet *infoAlddin;
	D3DXVECTOR2 prePosView;
	
public:
	ObjectManager();
	~ObjectManager();

	void Init(Graphic* graphic);

	//Update Game sau khoảng thời gian dt
	void Update(float dt, Keyboard* key);

	//Update Game sau khoảng thời gian dt
	void Update(float dt, Keyboard* key, Mouse* mouse);

	//Vẽ Object lên màn hình
	void Render();
};
