#pragma once
#include "Bullet.h"
#include "Player.h"
#include "Figure.h"
using namespace System::Drawing;

ref class Bullet : public Figure
{
private:
    bool Active;
public:
    Bullet(); //Конструктор
    
    Bullet(bool tag, float sizeX, float sizeY); //Конструктор с параметрами(tag, sizeX, sizeY)
    
    Bullet(float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(x, y, sizeX, sizeY)
    
    Bullet(bool tag, float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(tag, x, y, sizeX, sizeY)

    //~Bullet(); //Деструктор

    void SetActive(bool active); //Установить Active

    bool GetActive(); //Получить Active
    
    void AddBulletToTank(Figure^ tank, Bullet^ bullet); ///Присоединить снаряд к танку игрока
    
    void Move(int speedUp) override;
};

