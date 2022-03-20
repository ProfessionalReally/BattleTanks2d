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

	

	bulletsE[0] = gcnew BulletE(true, 16, 11);
	bulletsE[1] = gcnew BulletE(true, 16, 11);

	
	
	enemies[0] = gcnew Enemy(450, 45, 50, 45);
	enemies[1] = gcnew Enemy(500, 350, 50, 45);

	
	walls[0] = gcnew Wall(0, 1, 715, 19);
	walls[1] = gcnew Wall(0, 416, 715, 19);

	this->Text = "Battle Tanks Score: 0";
	AddBulletToEnemies(enemies);
	timer1->Start();
}

void BattleTanks2d::Form1::MoveBlocks(array<Block^>^% blocks, int speed)
{
	for (int i = 0; i < blocks->Length; i++)
	{
		float x; bool tag;
		tag = blocks[i]->GetTag();
		x = blocks[i]->GetX();
		blocks[i]->Move(speed);
		if (x < -65)
		{
			if (tag == true)
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
	/*throw gcnew System::NotImplementedException();*/
}

void BattleTanks2d::Form1::MoveEnemies(array<Enemy^>^% enemies, int speed)
{
	for (int i = 0; i < enemies->Length; i++)
	{
		float x = enemies[i]->GetX();
		enemies[i]->Move(speed);
		if (x < -65)
		{
			MoveObject(enemies[i]);
		}
	}
	/*throw gcnew System::NotImplementedException();*/
}

void BattleTanks2d::Form1::MoveObject(Figure^ enemies)
{
	enemies->SpawnX();
	enemies->SpawnYRandom();
	/*throw gcnew System::NotImplementedException();*/
}

void BattleTanks2d::Form1::AddBulletToEnemies(array<Enemy^>^% enemies)
{
	for (int i = 0; i < enemies->Length; i++)
	{
		bool tag; float x;
		tag = bulletsE[i]->GetTag();
		x = bulletsE[i]->GetX();
		if (tag == true)
		{
			if (x < -18)
			{
				bulletsE[i]->AddBulletToTank(enemies[i], bulletsE[i]);
			}
		}
	}
	/*throw gcnew System::NotImplementedException();*/
}

void BattleTanks2d::Form1::MoveEnemiesBullets(array<BulletE^>^% bulletsE, int speed)
{
	for (int i = 0; i < bulletsE->Length; i++)
	{
		bool Tag = bulletsE[i]->GetTag();
		if (Tag == true)
		{
			bulletsE[i]->Move(speed);
		}
	}
	/*throw gcnew System::NotImplementedException();*/
}

bool BattleTanks2d::Form1::BulletCollide(array<Enemy^>^% enemies)
{
	for (int i = 0; i < enemies->Length; i++)
	{
		if (bullet->Collide(enemies[i]))
		{
			MoveObject(enemies[i]);
			return true;
		}
	}
	return false;
}

System::Void BattleTanks2d::Form1::Form1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	switch (e->KeyCode)
	{
	case Keys::Up:
		up = true;
		break;
	case Keys::Down:
		down = true;
		break;
	case Keys::Space:
		space = true;
		break;
	}
	return System::Void();
}

System::Void BattleTanks2d::Form1::Form1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	switch (e->KeyCode)
	{
	case Keys::Up:
		up = false;
		break;
	case Keys::Down:
		down = false;
		break;
	case Keys::Space:
		space = false;
		break;
	}
	return System::Void();
}

void BattleTanks2d::Form1::Update(Object^ object, EventArgs^ e)
{
	if (tank->Collide(blocks[0]) || tank->Collide(blocks[1]) || tank->Collide(blocks[2]) || tank->Collide(blocks[3]) || tank->Collide(blocks[4]) || tank->Collide(blocks[5])
		|| tank->Collide(bulletsE[0]) || tank->Collide(bulletsE[1]) || tank->Collide(enemies[0]) || tank->Collide(enemies[1]) || tank->Collide(walls[0]) || tank->Collide(walls[1]))
	{
		if (tank->Pop(timer1))
		{
			Sleep(1000);
			fire = true;
			boost = 0;
			boostPlayer = 0;
			up = false;
			down = false;
			Init();
		}
	}
	if (space && fire == true)
	{
		bullet->AddBulletToTank(tank, bullet);
		bullet->SetActive(true);
		fire = false;
	}
	if (fire == false && bullet->GetActive() == true)
	{
		float x = bullet->GetX();
		if (x > 350)
		{
			bullet->SetActive(false);
			fire = true;
			bullet->SetX(0);
			bullet->SetY(0);
		}
		bullet->Move(0);
	}
	tank->MoveUpDown(up, down, boostPlayer);
	AddBulletToEnemies(enemies);
	if (BulletCollide(enemies))
	{
		int Score = tank->GetScore();
		Score++;
		tank->SetScore(Score);
		this->Text = "Battle Tanks Score: " + Score;
		if (Score == 5)
		{
			boost++;
			boostPlayer++;
		}
		if (Score == 10)
		{
			boost++;
		}
		if (Score == 15)
		{
			boost++;
			boostPlayer++;
		}
	}
	MoveBlocks(blocks, boost);
	MoveEnemies(enemies, boost);
	MoveEnemiesBullets(bulletsE, boost);
	Invalidate();
	/*throw gcnew System::NotImplementedException();*/
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

	images = bulletsE[0]->GetFigureImage();
	x = bulletsE[0]->GetX();
	y = bulletsE[0]->GetY();
	sizeX = bulletsE[0]->GetSizeX();
	sizeY = bulletsE[0]->GetSizeY();
	graphics->DrawImage(images, x, y, sizeX, sizeY);

	images = bulletsE[1]->GetFigureImage();
	x = bulletsE[1]->GetX();
	y = bulletsE[1]->GetY();
	sizeX = bulletsE[1]->GetSizeX();
	sizeY = bulletsE[1]->GetSizeY();
	graphics->DrawImage(images, x, y, sizeX, sizeY);

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

