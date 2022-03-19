#pragma once
#include "Figure.h"
using namespace System::Drawing;
using namespace std;
ref class Block : public Figure
{
public:
    Block(); //Конструктор
    
    Block(float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(X, y, sizeX, sizeY)

    Block(string* tag, float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(tag, x, y sizeX, sizeY)

    ~Block(); //Деструктор
};

