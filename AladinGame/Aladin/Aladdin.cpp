#include "Aladdin.h"



Aladdin::Aladdin()
{
}

Aladdin::Aladdin(Sprite *spAla, SpriteSheet *ifoAla)
{


	Tag = Object::Player;
	pathPNG = "aladdin.png";
	sprite = spAla;
	animAla = new AladdinAnimation(ifoAla);
	stateAla = new AladinState(this);


	position = D3DXVECTOR2(192, 1288);
	SetBound(30, 34);
	
}

AladinState *Aladdin::getState() {
	return stateAla;
}
void Aladdin::ChangeAnimation(float dt, Keyboard* key) {



	stateAla->CheckSide(key);
	switch (stateAla->GetState())
	{
	case AladinState::Standing:
		stateAla->StandState(key);
		animAla->standAnimation();
		break;
	case AladinState::Attack:

		stateAla->AttackState(key);
		animAla->attackAnimation();

		break;
	case AladinState::runattack:

		stateAla->AttackState(key);
		animAla->runAnimation();

		break;
	case AladinState::run:

		stateAla->RunState(key);
		animAla->runAnimation();
		break;
	case AladinState::jum:

		stateAla->jumState(key);
		animAla->jumpAnimation();
		break;
	case AladinState::fall:

		stateAla->fallState(key);
		animAla->fallAnimation();
		break;
	}
	stateAla->Update(dt, key);



}
void Aladdin::OnCollision(Object *obj, D3DXVECTOR2 distance, D3DXVECTOR2 disAla) {

}

void Aladdin::Update(float dt, Keyboard* key) {
	Object::Update(dt, key);
	animAla->SetFlipFlag(GetFlipFlag());
	animAla->Update(dt, key);

}
void Aladdin::Render(Viewport *viewport) {
	sprite->SetData(
		animAla->GetRect(),
		animAla->GetCenter(),
		animAla->GetPosition(),
		animAla->GetScale(),
		animAla->GetTransform(),
		animAla->GetAngle()
	);
	
	sprite->SetPosition(position);	
	RECT obj;
	obj.left = position.x;
	obj.top = position.y;
	obj.right = obj.left + 32;
	obj.bottom = obj.top + 32;
	if (viewport->isContains(obj)==true) {
		sprite->Render(viewport);
	}
	
}
Aladdin::~Aladdin()
{
}
