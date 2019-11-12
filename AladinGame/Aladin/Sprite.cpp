#include "Sprite.h"


Sprite::Sprite()
{
}

//Contructor
Sprite::Sprite(Graphic* graphic, const char* pathpng)
{
	this->graphic = graphic;
	texture = this->graphic->LoadTexture(pathpng, D3DCOLOR_XRGB(255, 0, 255));
	this->scale = D3DXVECTOR2(1, 1);
	transform = D3DXVECTOR2(0, 0);
	position = D3DXVECTOR2(0, 0);
	angle = 0;
	flipFlag = false;
	D3DXIMAGE_INFO info;
	HRESULT hr;
	ZeroMemory(&info, sizeof(info));
	//Lấy thông tin về hình ảnh
	hr = D3DXGetImageInfoFromFile(pathpng, &info);
	this->width = info.Width;
	this->height = info.Height;
	rect.left = 0;
	rect.right = info.Width;
	rect.top = 0;
	rect.bottom = info.Height;
	center = D3DXVECTOR2(info.Width / 2, info.Height / 2);

}

Sprite::~Sprite()
{
}

float Sprite::GetWidth()
{
	return this->width;
}

float Sprite::GetHeight()
{
	return this->height;
}

//Load lại Texture
void Sprite::SetTexture(const char* pathpng)
{
	texture = graphic->LoadTexture(pathpng, D3DCOLOR_XRGB(0, 0, 0));
}

RECT Sprite::GetRect()
{
	return this->rect;
}
void Sprite::SetRect(RECT rect)
{
	this->rect = rect;
}

//Vị trí
D3DXVECTOR2 Sprite::GetPosition()
{
	return position;
}
void Sprite::SetPosition(D3DXVECTOR2 position)
{
	this->position = position;
}

//Vị trí vẽ
D3DXVECTOR2 Sprite::GetCenter()
{
	return center;
}
void Sprite::SetCenter(D3DXVECTOR2 center)
{
	this->center = center;
}

//Phóng ảnh
D3DXVECTOR2 Sprite::GetScale()
{
	return scale;
}
void Sprite::SetScale(D3DXVECTOR2 scale)
{
	this->scale = scale;
}

//Dịch chuyển
D3DXVECTOR2 Sprite::GetTransform()
{
	return transform;
}
void Sprite::SetTransform(float x, float y)
{
	transform.x = x;
	transform.y = y;
}

//Góc quay
float Sprite::GetAngle()
{
	return angle;
}
void Sprite::SetAngle(float angle)
{
	this->angle = angle;
}


void Sprite::SetFlipFlag(bool flag)
{
	this->flipFlag = flag;
}

//Lật hình theo trục y
void Sprite::Flip(bool flag)
{
	if (flag)
	{
		scale = D3DXVECTOR2(-1.5, 1.5);
	}
	else scale = D3DXVECTOR2(1.5, 1.5);
}

//Set giá trị chuẩn bị vẽ
void Sprite::SetData(RECT rect, D3DXVECTOR2 center, D3DXVECTOR2 position, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle)
{
	this->rect = rect;
	this->center = center;
	this->position = position;
	this->scale = scale;
	this->angle = angle;
	this->transform = transform;
}
//Vẽ sprite
void Sprite::Update(float dt, Keyboard* key)
{

}

//Vẽ Sprite lên màn hình
void Sprite::Render(Viewport *viewport)
{
	graphic->DrawTexture(texture, rect, center, viewport->TransformPosition(position), scale, transform, angle, D3DCOLOR_XRGB(225, 225, 225));
}
