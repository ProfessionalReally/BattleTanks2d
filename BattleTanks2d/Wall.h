#pragma once
#include "Figure.h"
using namespace System::Drawing;
ref class Wall : public Figure
{
public:
    Wall(); //Конструктор
    
    Wall(float x, float y, float sizeX, float sizeY);  //Конструктор с параметрами(x, y, sizeX, sizeY)
    
    Wall(bool tag, float x, float y, float sizeX, float sizeY);  //Конструктор с параметрами(tag, x, y, sizeX, sizeY)

    ~Wall(); //Деструктор
};

