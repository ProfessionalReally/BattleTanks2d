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
    Figure(); //�����������

    Figure(string* tag, float sizeX, float sizeY); //����������� � �����������(tag, sizeX, sizeY)

    Figure(float x, float y, float sizeX, float sizeY); //����������� � �����������(x, y, sizeX, sizeY)

    Figure(string* tag, float x, float y, float sizeX, float sizeY); //����������� � �����������(tag, x, y, sizeX, sizeY)

    ~Figure(); //����������

    void SetX(float x); //���������� X

    void SetY(float y); //���������� Y

    void SetSizeX(float sizeX); //���������� SizeX

    void SetSizeY(float sizeY); //���������� SizeY

    void SetMoveSpeedUp(int movespeedUp); //���������� MoveSpeedUp

    void SetFigureImage(Image^ figureImage); //���������� FigureImage

    void SetTag(string* tag); //���������� Tag

    // ������� ��������� ������ �� �����
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

