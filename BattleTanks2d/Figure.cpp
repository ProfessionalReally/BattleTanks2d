#include "Figure.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

Figure::Figure() //Конструктор
{

}
Figure::Figure(bool tag, float sizeX, float sizeY) //Конструктор с параметрами(tag, sizeX, sizeY)
{
    Tag = tag;
    SizeX = sizeX;
    SizeY = sizeY;
}
Figure::Figure(float x, float y, float sizeX, float sizeY) //Конструктор с параметрами(x, y, sizeX, sizeY)
{
    X = x;
    Y = y;
    SizeX = sizeX;
    SizeY = sizeY;
}
Figure::Figure(bool tag, float x, float y, float sizeX, float sizeY) //Конструктор с параметрами(tag, x, y, sizeX, sizeY)
{
    Tag = tag;
    X = x;
    Y = y;
    SizeX = sizeX;
    SizeY = sizeY;
}
Figure::~Figure() //Деструктор
{
    ;
}
void Figure::SetX(float x) //Установить X
{
    X = x;
}
void Figure::SetY(float y) //Установить Y
{
    Y = y;
}
void Figure::SetSizeX(float sizeX) //Установить SizeX
{
    SizeX = sizeX;
}
void Figure::SetSizeY(float sizeY) //Установить SizeY
{
    SizeY = sizeY;
}
void Figure::SetMoveSpeedUp(int movespeedUp) //Установить MoveSpeedUp
{
    MoveSpeedUp = movespeedUp;
}
void Figure::SetFigureImage(Image^ figureImage) //Установить FigureImage
{
    FigureImage = figureImage;
}
void Figure::SetTag(bool tag) //Установить Tag
{
    Tag = tag;
}
// Функции получения данных из полей
float Figure::GetX()
{
    return this->X;
}
float Figure::GetY()
{
    return this->Y;
}
float Figure::GetSizeX()
{
    return this->SizeX;
}
float Figure::GetSizeY()
{
    return this->SizeY;
}
int Figure::GetMoveSpeedUp()
{
    return this->MoveSpeedUp;
}
Image^ Figure::GetFigureImage()
{
    return this->FigureImage;
}
bool Figure::GetTag()
{
    return this->Tag;
}
void Figure::Move(int speedUp)
{
    MoveSpeedUp = speedUp;
    X -= 4 + MoveSpeedUp;
}
void Figure::SpawnX()
{
    X += 865;
}
void Figure::SpawnYRandom()
{
    Random^ rnd = gcnew Random();
    Y = rnd->Next(100, 295);
}
bool Figure::Collide(Figure^ let)
{
    if (X < let->X + let->SizeX && X + SizeX > let->X && Y < let->Y + let->SizeY && SizeY + Y > let->Y)
    {
        return true;
    }
    return false;
}