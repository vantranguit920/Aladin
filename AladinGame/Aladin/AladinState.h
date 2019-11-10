#pragma once
#include <d3dx9.h>
#include "Keyboard.h"
#include "Object.h"
#include "Sound.h"
class AladinState
{
protected:
	Object *Aladdin;
	bool attack = false,delayattack;
	Sound *sound;
	GSound *attacksound;
	float delayattacktime = 0;
public:

	enum State
	{
		Standing,		//Đứng
		Attack,
		run,
		runattack,
	};
	State state;
	AladinState(Object *aladdin);
	AladinState();
	~AladinState();
	bool getAttack();

	void CheckSide(Keyboard* keyboard);
	void StandState(Keyboard* key);
	void AttackState(Keyboard* key);
	void RunState(Keyboard *key);




	State GetState();
	void SetState(State State);

	void Update(float dt, Keyboard* keyboard);
};

