#include "BulletE.h"
#include "Form1.h"
#include "Player.h"
#include "Figure.h"
BulletE::BulletE() //Конструктор
{

}
BulletE::BulletE(bool tag, float sizeX, float sizeY) : Figure(tag, sizeX, sizeY) //Конструктор с параметрами(tag, sizeX, sizeY)
{
	FigureImage = Image::FromFile("C:\\bullet.png");
}
BulletE::BulletE(float x, float y, float sizeX, float sizeY) : Figure(x, y, sizeX, sizeY)//Конструктор с параметрами(x, y, sizeX, sizeY)
{
	FigureImage = Image::FromFile("C:\\bullet.png");
}
BulletE::BulletE(bool tag, float x, float y, float sizeX, float sizeY) : Figure(tag, x, y, sizeX, sizeY)//Конструктор с параметрами(tag, x, y, sizeX, sizeY)
{
	FigureImage = Image::FromFile("C:\\bullet.png");
}
//BulletE::~BulletE() //Деструктор
//{
//	;
//}

void BulletE::AddBulletToTank(Enemy^% tank, BulletE^% bullet) //Присоединить снаряд к танку игрока
{
	float x, y;
	x = tank->GetX();
	y = tank->GetY();
	bullet->SetX(x - 15);
	bullet->SetY(y + 16);
}

void BulletE::Move(int speedUp)
{
	MoveSpeedUp = speedUp;
	X -= 6 + MoveSpeedUp;
}