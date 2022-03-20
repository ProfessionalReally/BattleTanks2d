#pragma once
#include "Bullet.h"
#include "BulletE.h"
#include "Player.h"
#include "Figure.h"
#include "Enemy.h"
#include "Wall.h"
#include "Player.h"
#include "Figure.h"
#include "Block.h"
#include <array>

namespace BattleTanks2d {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для Form1
	/// </summary>
	
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::Update);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(955, 535);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	// Данные игры
	private: Player^ tank;
	private: array<BulletE^>^ bulletsE = gcnew array<BulletE^>(2);
	private: array<Block^>^ blocks = gcnew array<Block^>(6);
	private: Bullet^ bullet;
	private: array<Enemy^>^ enemies = gcnew array<Enemy^>(2);
	private: array<Wall^>^ walls = gcnew array<Wall^>(2);
	private: bool up, down, space;
	private: bool fire = true;
	private: int boost = 0;
	private: int boostPlayer = 0;

	//Функции игры
	public: void Init();
	private: void MoveBlocks(array<Block^>^% blocks, int speed);
	private: void MoveEnemies(array<Enemy^>^% enemies, int speed);
	//private: void MoveObject();
	private: void AddBulletToEnemies(array<Enemy^>^% enemies);
	private: void MoveEnemiesBullets(array<BulletE^>^% bulletsE, int speed);
	private: bool BulletCollide(array<Enemy^>^% enemies);
	private: void MoveObject(Figure^ enemies);
	protected: virtual void OnPaint(PaintEventArgs^ e) override;

	// Отслеживание нажатия клавиш
	private: System::Void Form1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
	private: System::Void Form1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);

	private: void Update(Object^ object, EventArgs^ e);
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
