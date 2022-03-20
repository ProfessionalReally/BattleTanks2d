#pragma once
#include <string>
#include <random>
using namespace System::Drawing;
ref class Figure
{
protected:
    float X;
    float Y;
    float SizeX;
    float SizeY;
    int MoveSpeedUp;
    bool Tag;
    Image^ FigureImage;

public:
    Figure(); //Конструктор

    Figure(bool tag, float sizeX, float sizeY); //Конструктор с параметрами(tag, sizeX, sizeY)

    Figure(float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(x, y, sizeX, sizeY)

    Figure(bool tag, float x, float y, float sizeX, float sizeY); //Конструктор с параметрами(tag, x, y, sizeX, sizeY)

    ~Figure(); //Деструктор

    void SetX(float x); //Установить X

    void SetY(float y); //Установить Y

    void SetSizeX(float sizeX); //Установить SizeX

    void SetSizeY(float sizeY); //Установить SizeY

    void SetMoveSpeedUp(int movespeedUp); //Установить MoveSpeedUp

    void SetFigureImage(Image^ figureImage); //Установить FigureImage

    void SetTag(bool tag); //Установить Tag

    // Функции получения данных из полей
    float GetX();

    float GetY();

    float GetSizeX();

    float GetSizeY();

    int GetMoveSpeedUp();

    Image^ GetFigureImage();

    bool GetTag();

    virtual void Move(int speedUp);

    virtual void SpawnX();

    virtual void SpawnYRandom();

    bool Collide(Figure^ let);
};

