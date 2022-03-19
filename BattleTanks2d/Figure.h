#pragma once
#include <string>
#include <random>
using namespace System::Drawing;
using namespace std;
ref class Figure
{
protected:
    float X;
    float Y;
    float SizeX;
    float SizeY;
    int MoveSpeedUp;
    string* Tag;
    Image^ FigureImage;
public:
    Figure(); //Конструктор

    Figure(string* tag, float sizeX, float sizeY); //Конструктор с параметрами(tag, sizeX, sizeY)

    Figure(float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(x, y, sizeX, sizeY)

    Figure(string* tag, float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(tag, x, y, sizeX, sizeY)

    ~Figure(); //Деструктор

    void SetX(float x); //Установить X

    void SetY(float y); //Установить Y

    void SetSizeX(float sizeX); //Установить SizeX

    void SetSizeY(float sizeY); //Установить SizeY

    void SetMoveSpeedUp(int movespeedUp); //Установить MoveSpeedUp

    void SetFigureImage(Image^ figureImage); //Установить FigureImage

    void SetTag(string* tag); //Установить Tag

    // Функции получения данных из полей
    float GetX();

    float GetY();

    float GetSizeX();

    float GetSizeY();

    int GetMoveSpeedUp();

    Image^ GetFigureImage();

    string GetTag();

    virtual void Move(int speedUp);

    virtual void SpawnX();

    virtual void SpawnYRandom();

    bool Collide(Figure let);
};

