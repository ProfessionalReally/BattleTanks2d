#include "Bullet.h"

Bullet::Bullet() //�����������
{

}
Bullet::Bullet(string* tag, float sizeX, float sizeY) : Figure(tag, sizeX, sizeY) //����������� � �����������(tag, sizeX, sizeY)
{
	FigureImage = Image::FromFile("D:\\�������\\BattleTanks2d\\Resources\\bullet.png");
}
Bullet::Bullet(float x, float y, float sizeX, float sizeY) : Figure(x, y, sizeX, sizeY)//����������� � �����������(x, y, sizeX, sizeY)
{
	FigureImage = Image::FromFile("D:\\�������\\BattleTanks2d\\Resources\\bullet.png");
}
Bullet::Bullet(string* tag, float x, float y, float sizeX, float sizeY) : Figure(tag, x, y, sizeX, sizeY)//����������� � �����������(tag, x, y, sizeX, sizeY)
{
	FigureImage = Image::FromFile("D:\\�������\\BattleTanks2d\\Resources\\bullet.png");
}
Bullet::~Bullet() //����������
{
	;
}
void Bullet::SetActive(bool active) //���������� Active
{
	Active = active;
}
bool Bullet::GetActive() //�������� Active
{
	return this->Active;
}
void Bullet::AddBulletToPlayerTank(Player tank, Bullet bullet) //������������ ������ � ����� ������
{
	bullet.X = tank.X + 65;
	bullet.Y = tank.Y + 21;
}
void Bullet::Move(int speedUp) 
{
	MoveSpeedUp = speedUp;
	X += 8 + MoveSpeedUp;
}