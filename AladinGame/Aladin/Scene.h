#pragma once
#include "Graphic.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "ObjectManager.h"
#include "Sound.h"

class Scene
{
protected:
	ObjectManager* objManager;
public:

	Scene();
	~Scene();

	//Load Data Game
	void Init(Graphic* graphic);

	//Update Game sau khoảng thời gian dt
	void Update(float dt, Keyboard* key);

	//Update Game sau khoảng thời gian dt
	void Update(float dt, Keyboard* key,Mouse* mouse);

	//Vẽ Object lên màn hình
	void Render();
};

