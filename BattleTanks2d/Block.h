#pragma once
#include "Figure.h"
using namespace System::Drawing;
using namespace std;
ref class Block : public Figure
{
public:
    Block(); //�����������
    
    Block(float x, float y, float sizeX, float sizeY); //����������� � �����������(X, y, sizeX, sizeY)

    Block(string* tag, float x, float y, float sizeX, float sizeY); //����������� � �����������(tag, x, y sizeX, sizeY)

    ~Block(); //����������
};

