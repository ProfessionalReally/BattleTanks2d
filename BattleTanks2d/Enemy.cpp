#include "Enemy.h"

Enemy::Enemy()//Конструктор
{

}
Enemy::Enemy(float x, float y, float sizeX, float sizeY) : Figure(x, y, sizeX, sizeY) //Конструктор с параметрами(x, y, sizeX, sizeY)
{
    FigureImage = Image::FromFile("C:\\Enemy.png");
}

Enemy::Enemy(bool tag, float x, float y, float sizeX, float sizeY) : Figure(tag, x, y, sizeX, sizeY) //Конструктор с параметрами(tag, x, y, sizeX, sizeY)
{
    FigureImage = Image::FromFile("C:\\Enemy.png");
}

//Enemy::~Enemy() //Деструктор
//{
//    ;
//}

void Enemy::SpawnYRandom()
{
    Random^ rnd = gcnew Random();
    Y = rnd->Next(50, 330);
}
void Enemy::Move(int speedUp)
{
    MoveSpeedUp = speedUp;
    X -= 5 + MoveSpeedUp;
}