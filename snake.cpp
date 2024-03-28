#include "Header.h"
#include "Level.h"
#include "Menu.h"
#include "Header.h"
#include "SetUp.h"
#include <thread>

int main() {
	std::thread inputThread(Input);
	std::thread soundThread(Sound);
	FixConsoleWindow();
	SetConsoleWindow(1280, 720);
	MoveCenter();
	HideCursor();
	menu();
	inputThread.join();
	soundThread.join();

	return 0;
}