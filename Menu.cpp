#include "Menu.h"
#include "SetUp.h"
#include "Level.h"
#include "Header.h"


void menu()
{
    system("cls");
    setCellSize(10, 15);
    cursor = NEWGAME;
    page = MENU;
    dir = eDirection::STOP;
    state = NONE;
    backgroundmenu();
    start();

    while (true) {
        //Input();
        switch (dir) {
        case DOWN: {
            if (cursor != EXITGAME)
            {
                cursor = cursorMenu(cursor + 1);
            }
            break;
        }
        case UP: {
            if (cursor != NEWGAME) {
                cursor = cursorMenu(cursor - 1);
            }
            break;
        }
        default:
            break;
        }
        if (page == MENU) {
            switch (cursor) {
            case 0:
                start();
                break;
            case 1:
                introduction();
                break;
            case 2:
                settings();
                break;
            case 3:
                ranking();
                break;
            case 4:
                exits();
                break;
            default:
                break;
            }
        }
        switch(state){
        case ENTER: {
            if (page == MENU) {
                if (cursor == curHELP) {
                    backgroundmenu();
                    ogioithieu();
                    page = Page::HELP;
                }
                else if (cursor == NEWGAME)
                {
                    system("cls");
                    page = Page::PLAY;
                    level1();
                    return;
                }
                else if (cursor == EXITGAME)
                    CloseConsole();
            }
        }
        case EXIT:
        {
            if (page != MENU)
            {
                system("cls");
                menu();
                break;
            }
        }
        default:
            break;
        }
        state = State::NONE;
        dir = eDirection::STOP;
        Sleep(100);
    }
}


void start() {
    backColor(0);
    gotoXY(63, 12);
    textColor(3);
    cout << "START";
    gotoXY(59, 15);
    textColor(6);
    cout << "INTRODUCTION";
    gotoXY(61, 18);
    textColor(6);
    cout << "SETTINGS";
    gotoXY(62, 21);
    cout << "RANKING";
    gotoXY(63, 24);
    cout << "EXITS";
    backColor(12);
    for (int y = 10; y <= 26; y++) {
        for (int x = 53; x <= 76; x++) {
            gotoXY(x, y);
            if (x == 53 || x == 76 || y == 10 || y == 26)
                cout << " ";
        }
    }
}
void introduction() {
    backColor(0);
    gotoXY(63, 12);
    textColor(6);
    cout << "START";
    gotoXY(59, 15);
    textColor(3);
    cout << "INTRODUCTION";
    gotoXY(61, 18);
    textColor(6);
    cout << "SETTINGS";
    gotoXY(62, 21);
    cout << "RANKING";
    gotoXY(63, 24);
    cout << "EXITS";
    backColor(12);
    for (int y = 10; y <= 26; y++) {
        for (int x = 53; x <= 76; x++) {
            gotoXY(x, y);
            if (x == 53 || x == 76 || y == 10 || y == 26)
                cout << " ";
        }
    }
}
void settings() {
    backColor(0);
    gotoXY(63, 12);
    textColor(6);
    cout << "START";
    gotoXY(59, 15);
    cout << "INTRODUCTION";
    gotoXY(61, 18);
    textColor(3);
    cout << "SETTINGS";
    textColor(6);
    gotoXY(62, 21);
    cout << "RANKING";
    gotoXY(63, 24);
    cout << "EXITS";
    backColor(12);
    for (int y = 10; y <= 26; y++) {
        for (int x = 53; x <= 76; x++) {
            gotoXY(x, y);
            if (x == 53 || x == 76 || y == 10 || y == 26)
                cout << " ";
        }
    }
}
void ranking() {
    backColor(0);
    gotoXY(63, 12);
    textColor(6);
    cout << "START";
    gotoXY(59, 15);
    cout << "INTRODUCTION";
    gotoXY(61, 18);
    cout << "SETTINGS";
    textColor(3);
    gotoXY(62, 21);
    textColor(3);
    cout << "RANKING";
    textColor(6);
    gotoXY(63, 24);
    cout << "EXITS";
    backColor(12);
    for (int y = 10; y <= 26; y++) {
        for (int x = 53; x <= 76; x++) {
            gotoXY(x, y);
            if (x == 53 || x == 76 || y == 10 || y == 26)
                cout << " ";
        }
    }
}
void exits() {
    backColor(0);
    gotoXY(63, 12);
    textColor(6);
    cout << "START";
    gotoXY(59, 15);
    cout << "INTRODUCTION";
    gotoXY(61, 18);
    cout << "SETTINGS";
    gotoXY(62, 21);
    cout << "RANKING";
    textColor(3);
    gotoXY(63, 24);
    cout << "EXITS";
    backColor(12);
    for (int y = 10; y <= 26; y++) {
        for (int x = 53; x <= 76; x++) {
            gotoXY(x, y);
            if (x == 53 || x == 76 || y == 10 || y == 26)
                cout << " ";
        }
    }
}
void ogioithieu() {
    for (int y = 11; y <= 25; y++) {
        for (int x = 33; x <= 60; x++) {
            gotoXY(x, y);
            cout << " ";
        }
    }
    while (true) {
        if(state== EXIT)
			break;
        Sleep(500);
    }

}

void backgroundmenu() {
    //ve khung menu
    backColor(2);
    for (int x = 2; x < 130; x++) {
        gotoXY(x, 1);
        cout << " ";
    }
    for (int y = 2; y < 55; y++) {
        gotoXY(2, y);
        cout << " ";

    }
    for (int x = 2; x < 130; x++) {
        gotoXY(x, 54);
        cout << " ";
    }
    for (int y = 2; y < 55; y++) {
        gotoXY(129, y);
        cout << " ";

    }
    cout << endl;
    //to mau nen menu
    for (int y = 2; y < 54; y++) {
        for (int x = 3; x < 129; x++) {
            gotoXY(x, y);
            textColor(14);
            cout << (char)219;
        }
    }
    cout << endl;
    //ve chu game 
    //ve chu G
    for (int x = 34; x <= 36; x++) {
        gotoXY(x, 3);
        backColor(13);
        cout << " ";
    }
    for (int y = 4; y <= 7; y++) {
        gotoXY(33, y);
        cout << " ";
    }
    for (int x = 34; x <= 36; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    gotoXY(37, 4);
    cout << " ";
    for (int y = 6; y <= 7; y++) {
        gotoXY(37, y);
        cout << " ";
    }
    gotoXY(36, 6);
    cout << " ";
    //ve chu A
    for (int x = 39; x <= 41; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    for (int y = 5; y <= 7; y++) {
        gotoXY(40, y);
        cout << " ";
    }
    for (int x = 41; x <= 44; x++) {
        gotoXY(x, 6);
        cout << " ";
    }
    for (int y = 5; y <= 7; y++) {
        gotoXY(45, y);
        cout << " ";
    }
    for (int x = 44; x <= 46; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    gotoXY(41, 4);
    cout << " ";
    gotoXY(44, 4);
    cout << " ";
    for (int x = 42; x <= 43; x++) {
        gotoXY(x, 3);
        cout << " ";
    }
    //Ve chu M
    for (int x = 48; x <= 50; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    for (int y = 4; y <= 7; y++) {
        gotoXY(49, y);
        cout << " ";
    }
    for (int x = 48; x <= 50; x++) {
        gotoXY(x, 3);
        cout << " ";
    }
    gotoXY(50, 5);
    cout << " ";
    gotoXY(51, 6);
    cout << " ";
    gotoXY(52, 7);
    cout << " ";
    gotoXY(54, 5);
    cout << " ";
    gotoXY(53, 6);
    cout << " ";
    for (int x = 54; x <= 56; x++) {
        gotoXY(x, 3);
        cout << " ";
    }
    for (int y = 4; y <= 7; y++) {
        gotoXY(55, y);
        cout << " ";
    }
    for (int x = 54; x <= 56; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    //ve chu E
    for (int x = 58; x <= 63; x++) {
        gotoXY(x, 3);
        cout << " ";
    }
    for (int y = 4; y <= 7; y++) {
        gotoXY(59, y);
        cout << " ";
    }
    for (int x = 58; x <= 63; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    for (int x = 60; x <= 61; x++) {
        gotoXY(x, 5);
        cout << " ";
    }
    gotoXY(63, 4);
    cout << " ";
    gotoXY(63, 7);
    cout << " ";
    //ve chu SNAKE
    //ve chu S
    for (int x = 68; x <= 71; x++) {
        gotoXY(x, 3);
        cout << " ";
    }
    gotoXY(72, 4);
    cout << " ";
    gotoXY(67, 4);
    cout << " ";
    for (int x = 68; x <= 69; x++) {
        gotoXY(x, 5);
        cout << " ";
    }
    for (int x = 70; x <= 71; x++) {
        gotoXY(x, 6);
        cout << " ";
    }
    gotoXY(72, 7);
    cout << " ";
    for (int x = 68; x <= 71; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    gotoXY(67, 7);
    cout << " ";
    //Ve chu N
    for (int x = 74; x <= 76; x++) {
        gotoXY(x, 3);
        cout << " ";
    }
    for (int y = 4; y <= 7; y++) {
        gotoXY(75, y);
        cout << " ";
    }
    for (int x = 74; x <= 76; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    gotoXY(76, 5);
    cout << " ";
    for (int x = 77; x <= 78; x++) {
        gotoXY(x, 6);
        cout << " ";
    }
    for (int x = 78; x <= 80; x++) {
        gotoXY(x, 3);
        cout << " ";
    }
    for (int y = 4; y <= 7; y++) {
        gotoXY(79, y);
        cout << " ";
    }
    for (int x = 78; x <= 80; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    //ve chu A
    for (int x = 82; x <= 84; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    for (int y = 5; y <= 7; y++) {
        gotoXY(83, y);
        cout << " ";
    }
    for (int x = 84; x <= 87; x++) {
        gotoXY(x, 6);
        cout << " ";
    }
    for (int y = 5; y <= 7; y++) {
        gotoXY(88, y);
        cout << " ";
    }
    for (int x = 87; x <= 89; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    gotoXY(84, 4);
    cout << " ";
    gotoXY(87, 4);
    cout << " ";
    for (int x = 85; x <= 86; x++) {
        gotoXY(x, 3);
        cout << " ";
    }
    //ve chu K
    for (int x = 91; x <= 93; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    for (int y = 4; y <= 7; y++) {
        gotoXY(92, y);
        cout << " ";
    }
    for (int x = 91; x <= 93; x++) {
        gotoXY(x, 3);
        cout << " ";
    }
    gotoXY(93, 5);
    cout << " ";
    gotoXY(94, 4);
    cout << " ";
    for (int x = 95; x <= 96; x++) {
        gotoXY(x, 3);
        cout << " ";
    }
    gotoXY(94, 6);
    cout << " ";
    gotoXY(95, 7);
    cout << " ";
    for (int x = 95; x <= 96; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    //ve chu E
    for (int x = 98; x <= 103; x++) {
        gotoXY(x, 3);
        cout << " ";
    }
    for (int y = 4; y <= 7; y++) {
        gotoXY(99, y);
        cout << " ";
    }
    for (int x = 98; x <= 103; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    for (int x = 99; x <= 101; x++) {
        gotoXY(x, 5);
        cout << " ";
    }
    gotoXY(103, 4);
    cout << " ";
    gotoXY(103, 7);
    cout << " ";
    gotoXY(59, 11);
    for (int x = 82; x <= 84; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    for (int y = 5; y <= 7; y++) {
        gotoXY(83, y);
        cout << " ";
    }
    for (int x = 84; x <= 87; x++) {
        gotoXY(x, 6);
        cout << " ";
    }
    for (int y = 5; y <= 7; y++) {
        gotoXY(88, y);
        cout << " ";
    }
    for (int x = 87; x <= 89; x++) {
        gotoXY(x, 8);
        cout << " ";
    }
    gotoXY(84, 4);
    cout << " ";
    gotoXY(87, 4);
    cout << " ";
    for (int x = 85; x <= 86; x++) {
        gotoXY(x, 3);
        cout << " ";
    }
}