#pragma once
#include <time.h>
#include "Figure.h"
#include <Windows.h>

using namespace System::Drawing;
using namespace std;

ref class Player : public Figure
{
protected:
	bool Alive; //Жив ли игрок?
	int Score; //Очки
public:
    
    Player(); //Конструктор
    
    Player(float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(x, y, sizeX, sizeY)
    
    void MoveUpDown(bool up, bool down, int speed);
    
    bool Pop(Timer timer1);
    
};

