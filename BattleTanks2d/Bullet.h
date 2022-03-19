#pragma once
#include "Figure.h"
#include "Player.h"
using namespace System::Drawing;
using namespace std;

ref class Bullet : public Figure
{
private:
    bool Active;
public:
    Bullet(); //Конструктор
    
    Bullet(string* tag, float sizeX, float sizeY); //Конструктор с параметрами(tag, sizeX, sizeY)
    
    Bullet(float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(x, y, sizeX, sizeY)
    
    Bullet(string* tag, float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(tag, x, y, sizeX, sizeY)

    ~Bullet(); //Деструктор

    void SetActive(bool active); //Установить Active

    bool GetActive();
    
    virtual void AddBulletToPlayerTank(Player tank, Bullet bullet); //Присоединить снаряд к танку игрока
    
    void Move(int speedUp) override;
    
};

