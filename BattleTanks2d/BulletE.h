#pragma once
#include "Bullet.h"
#include "Figure.h"
#include "Form1.h"
#include "Enemy.h"
using namespace System::Drawing;
ref class BulletE : public Bullet
{
public:
    BulletE(); //Конструктор

    BulletE(bool tag, float sizeX, float sizeY); //Конструктор с параметрами(tag, sizeX, sizeY)

    BulletE(float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(x, y, sizeX, sizeY)

    BulletE(bool tag, float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(tag, x, y, sizeX, sizeY)

    ~BulletE(); //Деструктор

    void AddBulletToTank(Enemy tank, Bullet bullet) override; ///Присоединить снаряд к танку игрока

    void Move(int speedUp) override;
};

