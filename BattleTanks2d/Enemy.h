#pragma once
#include "Figure.h"
using namespace System;
using namespace System::Drawing;
ref class Enemy : public Figure
{
public:
    Enemy(); //Конструктор
    
    Enemy(float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(x, y, sizeX, sizeY)
    
    Enemy(bool tag, float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(tag, x, y, sizeX, sizeY)

    //~Enemy(); //Деструктор
    
    void SpawnYRandom() override;
    
    void Move(int speedUp) override;
    
};

