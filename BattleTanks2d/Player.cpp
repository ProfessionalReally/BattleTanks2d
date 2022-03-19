#include "Player.h"

Player::Player()
{

}
Player::Player(float x, float y, float sizeX, float sizeY) : Figure(x, y, sizeX, sizeY)
{
    FigureImage = Image::FromFile("D:\\проекты\\BattleTanks2d\\Resources\\Tank1.png");
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
bool Player::Pop(Timer timer1)
{
    Alive = false;
    timer1.Stop();

    Form form1 = Application.OpenForms["Form1"];
    Form form2 = Application.OpenForms["Start"];

    DialogResult vibor2 = MessageBox.Show("Счет: " + Score + "\nХотите начать заново?", "Вы проиграли!", MessageBoxButtons.YesNo);
    if (vibor2 == DialogResult.No)
    {
        form1.Close();
        form2.Show();
        return false;
    }
    else
        return true;
}