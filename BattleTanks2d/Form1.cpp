#include "Form1.h"
#include "Bullet.h"
#include "BulletE.h"
#include "Enemy.h"
#include "Wall.h"
#include "Player.h"
#include "Figure.h"
#include "Block.h"
#include "HowToPlay.h"
#include "Start.h"
#include <array>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;



BattleTanks2d::Form1::Form1(void)
{
	InitializeComponent();
	Init();
	Invalidate();
}
void BattleTanks2d::Form1::Init()
{
	tank = gcnew Player(12, 223, 70, 60);
	blocks[0] = gcnew Block(70, 45, 65, 55);
	blocks[1] = gcnew Block(70, 350, 65, 55);
	blocks[2] = gcnew Block(480, 45, 65, 55);
	blocks[3] = gcnew Block(480, 350, 65, 55);
	blocks[4] = gcnew Block(true, 280, 185, 70, 65);
	blocks[5] = gcnew Block(true, 720, 185, 70, 65);

	bullet = gcnew Bullet(true, 22, 18);

	/*array<BulletE^>^ bulletsE = gcnew array<BulletE^>(2);*/

	/*bulletsE[0] = gcnew BulletE(true, 16, 11);
	bulletsE[1] = gcnew BulletE(true, 16, 11);*/

	//array<Enemy^>^ enemies = gcnew array<Enemy^>(2);
	
	enemies[0] = gcnew Enemy(450, 45, 50, 45);
	enemies[1] = gcnew Enemy(500, 350, 50, 45);

	//array<Wall^>^ walls = gcnew array<Wall^>(2);
	
	walls[0] = gcnew Wall(0, 1, 715, 19);
	walls[1] = gcnew Wall(0, 416, 715, 19);

	this->Text = "Battle Tanks Score: 0";
	AddBulletToEnemies(enemies);
	timer1->Start();
}

void BattleTanks2d::Form1::MoveBlocks(array<Block^>^% blocks, int speed)
{
	/*array<Block^>^ blocks = gcnew array<Block^>(6);*/
	for (int i = 0; i < blocks->Length; i++)
	{
		float X = blocks[i]->GetX();
		bool Tag = blocks[i]->GetTag();
		blocks[i]->Move(speed);
		if (X < -65)
		{
			if (Tag)
			{
				blocks[i]->SpawnX();
				blocks[i]->SpawnYRandom();
			}
			else
			{
				blocks[i]->SpawnX();
			}
		}
	}
	throw gcnew System::NotImplementedException();
}

void BattleTanks2d::Form1::MoveEnemies()
{
	throw gcnew System::NotImplementedException();
}

void BattleTanks2d::Form1::MoveObject()
{
	throw gcnew System::NotImplementedException();
}

void BattleTanks2d::Form1::AddBulletToEnemies(array<Enemy^>^% enemies)
{
	/*for (int i = 0; i < enemies->Length; i++)
	{
		if (bullets[i].Tag == "bulletE")
		{
			if (bulletsE[i].X < -18)
			{
				bulletsE[i].AddBulletToTank(enemies[i], bulletsE[i]);
			}
		}
	}*/
}

void BattleTanks2d::Form1::MoveEnemiesBullets()
{
	throw gcnew System::NotImplementedException();
}

bool BattleTanks2d::Form1::BulletCollide()
{
	return false;
}

System::Void BattleTanks2d::Form1::Form1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	return System::Void();
}

System::Void BattleTanks2d::Form1::Form1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	return System::Void();
}

void BattleTanks2d::Form1::Update(Object^ object, EventArgs^ e)
{
	throw gcnew System::NotImplementedException();
}

void BattleTanks2d::Form1::OnPaint(PaintEventArgs^ e)
{
	Graphics^ graphics = e->Graphics;
	Image^ images;
	float x, y, sizeX, sizeY;
	images = tank->GetFigureImage();
	x = tank->GetX();
	y = tank->GetY();
	sizeX = tank->GetSizeX();
	sizeY = tank->GetSizeY();
	graphics->DrawImage(images, x, y, sizeX, sizeY);

	for (int i = 0; i < 6; i++)
	{
		images = blocks[i]->GetFigureImage();
		x = blocks[i]->GetX();
		y = blocks[i]->GetY();
		sizeX = blocks[i]->GetSizeX();
		sizeY = blocks[i]->GetSizeY();
		graphics->DrawImage(images, x, y, sizeX, sizeY);
	}
	images = bullet->GetFigureImage();
	x = bullet->GetX();
	y = bullet->GetY();
	sizeX = bullet->GetSizeX();
	sizeY = bullet->GetSizeY();
	graphics->DrawImage(images, x, y, sizeX, sizeY);

	images = enemies[0]->GetFigureImage();
	x = enemies[0]->GetX();
	y = enemies[0]->GetY();
	sizeX = enemies[0]->GetSizeX();
	sizeY = enemies[0]->GetSizeY();
	graphics->DrawImage(images, x, y, sizeX, sizeY);

	images = enemies[1]->GetFigureImage();
	x = enemies[1]->GetX();
	y = enemies[1]->GetY();
	sizeX = enemies[1]->GetSizeX();
	sizeY = enemies[1]->GetSizeY();
	graphics->DrawImage(images, x, y, sizeX, sizeY);
	//graphics->DrawImage(bulletsE[0]->GetFigureImage(), bulletsE[0]->GetX(), bulletsE[0]->GetY(), bulletsE[0]->GetSizeX(), bulletsE[0]->GetSizeY());
	//graphics->DrawImage(bulletsE[1]->GetFigureImage(), bulletsE[1]->GetX(), bulletsE[1]->GetY(), bulletsE[1]->GetSizeX(), bulletsE[1]->GetSizeY());
	images = walls[0]->GetFigureImage();
	x = walls[0]->GetX();
	y = walls[0]->GetY();
	sizeX = walls[0]->GetSizeX();
	sizeY = walls[0] ->GetSizeY();
	graphics->DrawImage(images, x, y, sizeX, sizeY);

	images = walls[1]->GetFigureImage();
	x = walls[1]->GetX();
	y = walls[1]->GetY();
	sizeX = walls[1]->GetSizeX();
	sizeY = walls[1]->GetSizeY();
	graphics->DrawImage(images, x, y, sizeX, sizeY);
}

