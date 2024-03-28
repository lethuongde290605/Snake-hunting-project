#pragma once
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

enum eDirection { STOP, DOWN, UP, RIGHT, LEFT };
enum Page { MENU, PLAY, HELP, LOADGAME};
enum cursorMenu { NEWGAME, curHELP, SETTING, RANKING, EXITGAME };
enum State { EXIT, ENTER, NONE};

extern eDirection dir;
extern Page page;
extern cursorMenu cursor;
extern State state;

extern bool isStart, isEatingSound, isPress;



void studentID(short length);
void Input();
void Sound();
