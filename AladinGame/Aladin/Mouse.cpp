#include "Mouse.h"

Mouse::Mouse(HWND hWnd)
{
	this->di = 0;
	this->did = 0;
	this->hWnd = hWnd;
}

Mouse::~Mouse()
{
}

//Cài đặt bàn phím
bool Mouse::Init()
{
	HRESULT hr = DirectInput8Create(
		GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&this->di,		//Con trỏ nhận dữ liệu trả về
		NULL);					

	if (FAILED(hr))
	{
		return false;
	}

	// Tạo bàn phím GUID_Mouse
	hr = this->di->CreateDevice(GUID_SysMouse, &this->did, NULL);
	if (FAILED(hr))
	{
		return false;
	}

	// Dạng dữ liệu được nhận
	hr = this->did->SetDataFormat(&c_dfDIMouse2);
	if (FAILED(hr))
	{
		return false;
	}

	//Loại hoạt động 
	hr = this->did->SetCooperativeLevel(this->hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE); //DISCL_FOREGROUND chỉ hoạt động khi của sổ hWnd đang được handle
	if (FAILED(hr))
	{
		return false;
	}

	//Yêu cầu thiết bị
	hr = this->did->Acquire();
	if (FAILED(hr))
	{
		return false;
	}
	return true;
}

//Lấy trạng thái bàn phím
void Mouse::GetStage()
{
	HRESULT hr = this->did->GetDeviceState(sizeof(DIMOUSESTATE2), (LPVOID)&this->mouseState);
	
	if (FAILED(hr))
	{
		while (this->did->Acquire() == DIERR_INPUTLOST);
	}
}

//xet xem button nao duoc nhan qua bien
bool Mouse::IsMouseDown(int button)
{
	return ((mouseState.rgbButtons[button] & 0x80) != 0);
}

//Trạng thái chuột ở x
float Mouse::MouseDX()
{
	return mouseState.lX;
}

//Trạng thái chuột ở y
float Mouse::MouseDY()
{
	return mouseState.lY;
}

//Trạng thái chuột ở z
float Mouse::MouseDZ()
{
	return mouseState.lZ;
}

//Hủy chuột
void Mouse::KillMouse()
{
	if (did != NULL)
	{
		this->did->Unacquire();
		this->did->Release();
		this->did = NULL;
	}
}
