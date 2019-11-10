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
	
	
	position = D3DXVECTOR2(300, 200);
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
	sprite->Render(viewport);
}
Aladdin::~Aladdin()
{
}
