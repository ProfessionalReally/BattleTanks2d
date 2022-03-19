#include "Player.h"
#include "Form1.h"
#include "Start.h"
#include "HowToPlay.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

Player::Player()
{

}
Player::Player(float x, float y, float sizeX, float sizeY) : Figure(x, y, sizeX, sizeY)
{
    FigureImage = Image::FromFile("C:\\Users\\79012\\source\\repos\\BattleTanks2d-master\\Resources\\Tank1.png");
    Alive = true;
    Score = 0;
}
void Player::MoveUpDown(bool up, bool down, int speed)
{
    if (up)
    {
        Y -= 4 + speed;
    }
    if (down)
    {
        Y += 4 + speed;
    }
}
bool Player::Pop(System::Object^ sender, System::EventArgs^ e, Timer timer1)
{
    /*Alive = false;
    timer1.Stop();

    Form^ form1 = gcnew Form;
    Form form1 = Application::OpenForms["Form1"]
    Form form2 = Application.OpenForms["Start"];

    DialogResult vibor2 = MessageBox.Show("Счет: " + Score + "\nХотите начать заново?", "Вы проиграли!", MessageBoxButtons.YesNo);
    if (vibor2 == DialogResult.No)
    {
        form1.Close();
        form2.Show();
        return false;
    }
    else*/
        return true;
}