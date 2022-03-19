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
    Bullet(); //�����������
    
    Bullet(string* tag, float sizeX, float sizeY); //����������� � �����������(tag, sizeX, sizeY)
    
    Bullet(float x, float y, float sizeX, float sizeY); //����������� � �����������(x, y, sizeX, sizeY)
    
    Bullet(string* tag, float x, float y, float sizeX, float sizeY); //����������� � �����������(tag, x, y, sizeX, sizeY)

    ~Bullet(); //����������

    void SetActive(bool active); //���������� Active

    bool GetActive();
    
    virtual void AddBulletToPlayerTank(Player tank, Bullet bullet); //������������ ������ � ����� ������
    
    void Move(int speedUp) override;
    
};

