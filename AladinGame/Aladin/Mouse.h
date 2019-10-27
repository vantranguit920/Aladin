#pragma once
#include <dinput.h>

class Mouse
{
	LPDIRECTINPUT8 di;			//Đối tượng nhập xuất
	LPDIRECTINPUTDEVICE8 did;	//Thiết bị nhập xuất
	HWND hWnd;					//Handle cửa sổ vẽ
	DIMOUSESTATE2  mouseState;
public:
	Mouse(HWND hWnd);
	~Mouse();

	//Cài đặt chuột
	bool Init();

	//Lấy trạng thái chuột
	void GetStage();

	//Kiểm tra trạng thái nút có được nhấn
	bool IsMouseDown(int button);	
	float MouseDX();					
	float MouseDY();					
	float MouseDZ();

	//Hủy chuột
	void KillMouse();
};

