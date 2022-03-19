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
	Player^ tank = gcnew Player(12, 223, 70, 60);
	/*auto arr = gcnew cli::array<Block^>(42);*/
	//array<Block^>^ blocks = gcnew array<Block^>(6);
	blocks[0] = gcnew Block(70, 45, 65, 55);
	blocks[1] = gcnew Block(70, 350, 65, 55);
	blocks[2] = gcnew Block(480, 45, 65, 55);
	blocks[3] = gcnew Block(480, 350, 65, 55);
	blocks[4] = gcnew Block(true, 280, 185, 70, 65);
	blocks[5] = gcnew Block(true, 720, 185, 70, 65);

	Bullet^ bullet = gcnew Bullet("bulletP", 22, 18);

	//array<BulletE^>^ bulletsE = gcnew array<BulletE^>(2);

	bulletsE[0] = gcnew BulletE("bulletE", 16, 11);
	bulletsE[1] = gcnew BulletE("bulletE", 16, 11);

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

void BattleTanks2d::Form1::MoveBlocks(array<Block^>^ blocks(), int speed)
{
	array<Block^>^ blocks = gcnew array<Block^>(6);
	for (int i = 0; i < blocks->Length; i++)
	{
		blocks(i)->Move(speed);
		if (blocks[i].X < -65)
		{
			if (blocks[i].Tag == "blockM")
			{
				blocks[i].SpawnX();
				blocks[i].SpawnYRandom();
			}
			else
			{
				blocks[i].SpawnX();
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

void BattleTanks2d::Form1::AddBulletToEnemies()
{
	throw gcnew System::NotImplementedException();
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

	graphics->DrawImage(tank.GetFigureImage(), tank.GetX(), tank.GetY(), tank.GetSizeX(), tank.GetSizeY());
	for (int i = 0; i < 6; i++)
	{
		graphics->DrawImage(blocks[i]->GetFigureImage(), blocks[i]->GetX(), blocks[i]->GetY(), blocks[i]->GetSizeX(), blocks[i]->GetSizeY());
	}
	graphics->DrawImage(bullet.GetFigureImage(), bullet.GetX(), bullet.GetY(), bullet.GetSizeX(), bullet.GetSizeY());

	graphics->DrawImage(enemies[0]->GetFigureImage(), enemies[0]->GetX(), enemies[0]->GetY(), enemies[0]->GetSizeX(), enemies[0]->GetSizeY());
	graphics->DrawImage(enemies[1]->GetFigureImage(), enemies[1]->GetX(), enemies[1]->GetY(), enemies[1]->GetSizeX(), enemies[1]->GetSizeY());

	graphics->DrawImage(bulletsE[0]->GetFigureImage(), bulletsE[0]->GetX(), bulletsE[0]->GetY(), bulletsE[0]->GetSizeX(), bulletsE[0]->GetSizeY());
	graphics->DrawImage(bulletsE[1]->GetFigureImage(), bulletsE[1]->GetX(), bulletsE[1]->GetY(), bulletsE[1]->GetSizeX(), bulletsE[1]->GetSizeY());

	graphics->DrawImage(walls[0]->GetFigureImage(), walls[0]->GetX(), walls[0]->GetY(), walls[0]->GetSizeX(), walls[0]->GetSizeY());
	graphics->DrawImage(walls[1]->GetFigureImage(), walls[1]->GetX(), walls[1]->GetY(), walls[1]->GetSizeX(), walls[1]->GetSizeY());
}

