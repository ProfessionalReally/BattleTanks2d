#include "Bullet.h"
#include "Player.h"
#include "Figure.h"
#include "Form1.h"

Bullet::Bullet() //Конструктор
{

}
Bullet::Bullet(bool tag, float sizeX, float sizeY) : Figure(tag, sizeX, sizeY) //Конструктор с параметрами(tag, sizeX, sizeY)
{
	FigureImage = Image::FromFile("C:\\bullet.png");
}
Bullet::Bullet(float x, float y, float sizeX, float sizeY) : Figure(x, y, sizeX, sizeY)//Конструктор с параметрами(x, y, sizeX, sizeY)
{
	FigureImage = Image::FromFile("C:\\bullet.png");
}
Bullet::Bullet(bool tag, float x, float y, float sizeX, float sizeY) : Figure(tag, x, y, sizeX, sizeY)//Конструктор с параметрами(tag, x, y, sizeX, sizeY)
{
	FigureImage = Image::FromFile("C:\\bullet.png");
}
//Bullet::~Bullet() //Деструктор
//{
//	;
//}
void Bullet::SetActive(bool active) //Установить Active
{
	Active = active;
}
bool Bullet::GetActive() //Получить Active
{
	return this->Active;
}
void Bullet::AddBulletToTank(Figure^ tank, Bullet^ bullet) //Присоединить снаряд к танку игрока
{
	float x, y;
	x = tank->GetX();
	y = tank->GetY();
	bullet->SetX(x + 65);
	bullet->SetY(y + 21);
}
void Bullet::Move(int speedUp) 
{
	MoveSpeedUp = speedUp;
	X += 8 + MoveSpeedUp;
}