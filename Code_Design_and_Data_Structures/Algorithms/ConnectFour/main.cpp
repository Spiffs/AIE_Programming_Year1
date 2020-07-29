#include "ConnectFourApp.h"
#include "../AIE_RayLib_Template/raylib/src/raylib.h"

int main() {
	
	// allocation
	auto app = new ConnectFourApp();

	const int WindowHeight = 1280;
	const int WindowWidth = 720;

	// initialise and loop
	InitWindow(WindowHeight, WindowWidth, "AIE");

	// deallocation
	delete app;

	return 0;
}