#include "ObjectManager.h"
#include "string.h"

ObjectManager::ObjectManager()
{
}
ObjectManager::~ObjectManager()
{
	delete aladin;
	delete viewport;

}

//Load Data Game
void ObjectManager::Init(Graphic* graphic)
{
	this->sound = new Sound(graphic->GetHwnd());
	this->sound->Init_DirectSound();
	soundGame = this->sound->LoadSound("./Sound/PrinceAli.wav");
	spriteAladdin = new Sprite(graphic, "Aladdin_Sprite.png");
	infoAlddin = new SpriteSheet("Aladdin-Animations.xml");
	viewport = new Viewport(0, 1120);
	map = new Map(graphic);
	aladin = new Aladdin(spriteAladdin,infoAlddin);
	
	prePosView = viewport->GetPosition();
}

//Update Game
void ObjectManager::Update(float dt, Keyboard* keyboard)
{
	
}

void ObjectManager::Update(float dt, Keyboard* keyboard, Mouse* mouse)
{
	aladin->ChangeAnimation(dt, keyboard);

	if (prePosView != viewport->GetPosition())
	{
		prePosView = viewport->GetPosition();
	}


	aladin->Update(dt, keyboard);
	viewport->Update(dt, keyboard, aladin->GetPosition(), aladin->GetVelocity(), map->listStage);
	
	this->sound->LoopSound(this->soundGame);
}

//Vẽ
void ObjectManager::Render()
{
	map->Render(viewport);
	aladin->Render(viewport);
	
}
