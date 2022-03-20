#pragma once
#include <time.h>
#include "Bullet.h"
#include "Player.h"
#include "Figure.h"
#include <Windows.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class Player : public Figure
{
protected:
	bool Alive; //Жив ли игрок?
	int Score; //Очки
public:
    
    Player(); //Конструктор
    
    Player(float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(x, y, sizeX, sizeY)
    
    void MoveUpDown(bool up, bool down, int speed);
    
    bool Pop(Timer^% timer1);

    bool GetAlive(); //Получить Alive

    int GetScore(); //Получить Score

    void SetAlive(bool alive); //Придать значение Alive

    void SetScore(int score); //Придать значение Score
    
};

