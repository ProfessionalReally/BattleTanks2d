#include "Wall.h"

Wall::Wall() //�����������
{

}
Wall::Wall(float x, float y, float sizeX, float sizeY) : Figure(x, y, sizeX, sizeY) //����������� � �����������(x, y, sizeX, sizeY)
{
    FigureImage = Image::FromFile("D:\\�������\\BattleTanks2d\\Resources\\wall.png");
}

Wall::Wall(bool tag, float x, float y, float sizeX, float sizeY) : Figure(tag, x, y, sizeX, sizeY) //����������� � �����������(tag, x, y, sizeX, sizeY)
{
    FigureImage = Image::FromFile("D:\\�������\\BattleTanks2d\\Resources\\wall.png");
}

Wall::~Wall() //����������
{
    ;
}