#include "Form1.h"
#include "Bullet.h"
#include "Player.h"
#include "Figure.h"
#include "Block.h"
#include "HowToPlay.h"
#include "Start.h"
#include <array>
using namespace System;

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
	array<Block^>^ blocks = gcnew array<Block^>(6);
	blocks[0] = gcnew Block(70, 45, 65, 55);
	blocks[1] = gcnew Block(70, 350, 65, 55);
	blocks[2] = gcnew Block(480, 45, 65, 55);
	blocks[3] = gcnew Block(480, 350, 65, 55);
	blocks[4] = gcnew Block(true, 280, 185, 70, 65);
	blocks[5] = gcnew Block(true, 720, 185, 70, 65);
}

void BattleTanks2d::Form1::MoveBlocks()
{
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
