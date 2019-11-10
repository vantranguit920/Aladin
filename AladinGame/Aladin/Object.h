#pragma once
#include "Sprite.h"
#include "Mouse.h"
#include "Collision.h"
#include "Sound.h"

class Object
{
protected:
	Sprite* sprite;
	float width;		
	float height;

	D3DXVECTOR2 position;			//Vị trí vẽ
	D3DXVECTOR2 velocity;			//Vector vận tốc
	D3DXVECTOR2 positionStart;		//Vị trí bắt đầu
	D3DXVECTOR2 transform;			//Vector dịch chuyển
	RECT bound;						//Khung
	float angle;					//Góc quay
	bool flipFlag;					//Cờ lật
	string name;					//Tên

public:
	int id;
	enum tag
	{
		Player,
		Bar
	}Tag;
	
	Object();
	~Object();
	void SetBound(float width, float height);
	static tag GetTag(string name);
	void SetTag(tag name);
	virtual bool GetFlipFlag();
	virtual void SetFlipFlag(bool flag);

	//Khung va chạm
	virtual RECT GetBound();
	virtual RECT GetBound(float width, float height);
	virtual void SetBound(RECT bound);

	//Thông tin frame
	virtual float GetWidth();
	virtual void SetWidth(float width);
	virtual float GetHeight();
	virtual void SetHeight(float height);

	//Vị trí
	virtual D3DXVECTOR2 GetPosition();
	virtual D3DXVECTOR2 GetPositionStart();
	virtual void SetPosition(D3DXVECTOR2 position);
	virtual void SetPositionStart(D3DXVECTOR2 position);
	virtual void SetPositionX(float x);
	virtual void SetPositionY(float y);

	//Vận tốc
	virtual D3DXVECTOR2 GetVelocity();
	virtual void SetVelocity(D3DXVECTOR2 velocity);
	virtual void SetVelocityX(float vx);
	virtual void SetVelocityY(float vy);
	virtual void SetVelocity(float x, float y);

	//Dịch chuyển
	virtual D3DXVECTOR2 GetTransform();
	virtual void SetTransform(D3DXVECTOR2 transform);
	virtual void SetTransform(float x, float y);

	//Góc
	virtual float GetAngle();
	virtual void SetAngle(float angle);

	//Tính khoảng cách trong khoảng dt
	virtual D3DXVECTOR2 Distance(float dt);

	virtual void Update(float dt, Keyboard* key);
	virtual void Update(float dt, Keyboard* key, Mouse* mouse);
	virtual void Render();

	//Va chạam
	virtual void OnCollision(Object *obj, D3DXVECTOR2 distance);
	virtual void OnCollision(Object *obj) {}
	virtual void OnCollision() {}

	RECT GetBoard(D3DXVECTOR2 distance);
	virtual void AddVelocity(float x, float y);
	virtual void New();
};

