#pragma once
#include <ctime>
#include "Header.h"
#include "Menu.h"
#include <Windows.h>
#include <ctime>
#include <thread>

using namespace std;


void SetUpLvl();
void Draw(int, int);
void Input();
void Logic();
void drawSnFr();
void snakeGate();
void drawBox(int x, int y, int width, int height,int, int);
void level1();
void level2();
void overGame();