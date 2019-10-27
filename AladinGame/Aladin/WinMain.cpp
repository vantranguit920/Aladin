#include <windows.h>
#include "Game.h"
#include "GameDefine.h"
using namespace Define;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Game game(hInstance, WinWidth, WinHeight, "Aladin", 60);

	game.Init();
	game.Run();

	return 0;
}


