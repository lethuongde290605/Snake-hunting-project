#include "Level.h"
#include "SetUp.h"
#include "Sound.h"

// eDirection dir;
struct Position
{
    int x;
    int y;
};

bool gameOver, isGate, isSnakeGoToGate;
// bool isStart;
int xBase, yBase, widthBase, heightBase;
Position fruit;
Position snake[50];
int snakeLength;
Position preSnake;
Position Gate;
int mainColor, frameColor;

void level1()
{
    setCellSize(15, 15);

    srand(time(NULL));
    SetUpLvl();
    mainColor = 6;
    frameColor = 5;
    Draw(mainColor, frameColor);

    while (!gameOver)
    {
        Logic();
        gotoXY(0, 0);
        textColor(1);
        cout << "Score: " << snakeLength - 3;
        isEatingSound = false;
        drawSnFr();
        if (isGate && snake[snakeLength - 1].x == Gate.x && snake[snakeLength - 1].y == Gate.y)
        {
            Sleep(1000);
            system("cls");
            level2();
        }
        if (state == EXIT)
        {
            menu();
        }
        Sleep(100);
    }

    overGame();

    menu();
}

void level2()
{
    setCellSize(15, 15);

    srand(time(NULL));
    SetUpLvl();
    mainColor = 2;
    frameColor = 3;
    Draw(mainColor, frameColor);

    while (!gameOver)
    {
        Logic();
        gotoXY(0, 0);
        textColor(1);
        cout << "Score: " << snakeLength - 3;
        isEatingSound = false;
        drawSnFr();
        if (isGate && snake[snakeLength - 1].x == Gate.x && snake[snakeLength - 1].y == Gate.y)
        {
            Sleep(1000);
            menu();
            return;
        }
        if (state == EXIT)
        {
            menu();
        }
        Sleep(70);
    }
    overGame();

    menu();
}

void SetUpLvl()
{
    dir = STOP;
    gameOver = false;
    isStart = false;
    isGate = false;
    isSnakeGoToGate = false;
    snakeLength = 3;
    xBase = 10, yBase = 5;
    widthBase = 40, heightBase = 32;
    dir = STOP;
    Gate.x = 0;
    Gate.y = 0;

    snake[0].x = xBase + widthBase / 2;
    snake[0].y = yBase + heightBase / 2;
    snake[1].x = snake[0].x - 1;
    snake[1].y = snake[0].y;
    snake[2].x = snake[0].x - 2;
    snake[2].y = snake[0].y;

    fruit.x = rand() % (widthBase) + xBase;
    fruit.y = rand() % (heightBase) + yBase;
}

void Draw(int mainColor, int frameColor)
{
    drawBox(xBase - 1, yBase - 1, widthBase + 1, heightBase + 1, mainColor, frameColor);
    drawSnFr();
}

void Logic()
{
    if (snake[0].x == fruit.x && snake[0].y == fruit.y)
    {
        isEatingSound = true;
        fruit.x = rand() % (widthBase) + xBase;
        fruit.y = rand() % (heightBase) + yBase;
        snakeLength++;
        if (snakeLength == 8 && !isGate)
        {
            isGate = true;
            snakeGate();
        }
    }

    preSnake = snake[snakeLength - 1];

    if (snake[0].x == Gate.x && snake[0].y == Gate.y)
        isSnakeGoToGate = true;
    if (isStart)
    {
        for (int i = snakeLength - 1; i >= 1; i--)
            snake[i] = snake[i - 1];
    }

    if (!isSnakeGoToGate)
    {
        switch (dir)
        {
        case UP:
            snake[0].y--;
            break;
        case RIGHT:
            snake[0].x++;
            break;
        case LEFT:
            snake[0].x--;
            break;
        case DOWN:
            snake[0].y++;
            break;
        default:
            break;
        }
    }

    int temp = (isEatingSound) ? snakeLength - 1 : snakeLength;

    for (int i = 1; i < temp; i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y && !isSnakeGoToGate)
            gameOver = true;
    }

    if (snake[0].x < xBase || snake[0].x >= xBase + widthBase || snake[0].y < yBase || snake[0].y >= yBase + heightBase)
    {
        gameOver = true;
    }
}

// draw snake and fruit
void drawSnFr()
{
    if (!isGate)
    {
        highLight(fruit.x, fruit.y, 7);
        gotoXY(fruit.x, fruit.y);
        textColor(0);
        studentID(snakeLength);
    }
    for (int i = 0; i < snakeLength; i++)
    {
        if (snake[i].x == Gate.x && snake[i].y == Gate.y)
            highLight(snake[i].x, snake[i].y, 3);
        else
        {
            highLight(snake[i].x, snake[i].y, (i == 7) ? 3 : i);
            gotoXY(snake[i].x, snake[i].y);
            textColor(7);
            studentID(i);
        }
        if (isStart && dir != STOP)
            highLight(preSnake.x, preSnake.y, mainColor);
    }
}

void snakeGate()
{
    Gate.x = rand() % (widthBase - 1) + (xBase + 1);
    Gate.y = rand() % (heightBase - 1) + (yBase + 1);
    highLight(Gate.x, Gate.y, 3);
}

void drawBox(int x, int y, int width, int height, int mainColor, int frameColor)
{
    for (int i = x; i <= x + width; i++)
    {
        for (int j = y; j <= y + height; j++)
        {
            if (i == x || i == x + width || j == y || j == y + height)
            {
                highLight(i, j, frameColor);
            }
            else
                highLight(i, j, mainColor);
        }
        cout << endl;
    }
}

void overGame()
{
    // system("cls");
    int i = 0;
    while (i < 10)
    {
        for (int j = snakeLength - 1; j >= 0; j--)
        {
            int color = j + i + 1;
            if (color == 6)
                color = 0;
            highLight(snake[j].x, snake[j].y, color);
        }
        i++;
        Sleep(100);
    }
    Sleep(2000);
}