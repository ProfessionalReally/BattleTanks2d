#pragma once
#include "Bullet.h"
#include "Figure.h"
#include "Enemy.h"
using namespace System::Drawing;

ref class BulletE : public Figure
{
public:
    BulletE(); //�����������

    BulletE(bool tag, float sizeX, float sizeY); //����������� � �����������(tag, sizeX, sizeY)

    BulletE(float x, float y, float sizeX, float sizeY); //����������� � �����������(x, y, sizeX, sizeY)

    BulletE(bool tag, float x, float y, float sizeX, float sizeY); //����������� � �����������(tag, x, y, sizeX, sizeY)

    //~BulletE(); //����������

    void AddBulletToTank(Figure^ tank, Bullet^ bullet); ///������������ ������ � ����� ������

    void Move(int speedUp) override;
};

