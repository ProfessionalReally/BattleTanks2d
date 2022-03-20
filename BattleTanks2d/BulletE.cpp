#include "BulletE.h"

BulletE::BulletE() //�����������
{

}
BulletE::BulletE(bool tag, float sizeX, float sizeY) : Figure(tag, sizeX, sizeY) //����������� � �����������(tag, sizeX, sizeY)
{
	FigureImage = Image::FromFile("C:\\bullet.png");
}
BulletE::BulletE(float x, float y, float sizeX, float sizeY) : Figure(x, y, sizeX, sizeY)//����������� � �����������(x, y, sizeX, sizeY)
{
	FigureImage = Image::FromFile("C:\\bullet.png");
}
BulletE::BulletE(bool tag, float x, float y, float sizeX, float sizeY) : Figure(tag, x, y, sizeX, sizeY)//����������� � �����������(tag, x, y, sizeX, sizeY)
{
	FigureImage = Image::FromFile("C:\\bullet.png");
}
//BulletE::~BulletE() //����������
//{
//	;
//}
void BulletE::AddBulletToTank(Figure^ tank, Bullet^ bullet) //������������ ������ � ����� ������
{
	float x, y;
	x = tank->GetX();
	y = tank->GetY();
	bullet->SetX(x + 65);
	bullet->SetY(y + 21);
}
void BulletE::Move(int speedUp)
{
	MoveSpeedUp = speedUp;
	X += 8 + MoveSpeedUp;
}