#pragma once
#using <system.drawing.dll>

#include "HowToPlay.h"
#include "Form1.h"
namespace BattleTanks2d {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Start
	/// </summary>
	public ref class Start : public System::Windows::Forms::Form
	{
	public:
		Start(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Start()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 7.8F, System::Drawing::FontStyle::Bold));
			this->button1->Location = System::Drawing::Point(61, 62);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 52);
			this->button1->TabIndex = 0;
			this->button1->Text = L"»√–ј“№";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Start::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(61, 119);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(109, 52);
			this->button2->TabIndex = 1;
			this->button2->Text = L"ƒл€ тех кто любит читать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Start::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Red;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold));
			this->button3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button3->Location = System::Drawing::Point(61, 238);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(109, 52);
			this->button3->TabIndex = 2;
			this->button3->Text = L"¬ыход";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Start::button3_Click);
			// 
			// Start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(238, 332);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Start";
			this->Text = L"Start";
			this->Load += gcnew System::EventHandler(this, &Start::Start_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Application::Exit();
	}
	private: System::Void Start_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Form1^ example = gcnew Form1;
		example->Show();

		example->Owner = this;
		this->Hide();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		HowToPlay^ prav = gcnew HowToPlay;
		prav->Show();
	}
};
}
