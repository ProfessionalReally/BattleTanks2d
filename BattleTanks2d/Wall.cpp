#include "Wall.h"

Wall::Wall() //Конструктор
{

}
Wall::Wall(float x, float y, float sizeX, float sizeY) : Figure(x, y, sizeX, sizeY) //Конструктор с параметрами(x, y, sizeX, sizeY)
{
    FigureImage = Image::FromFile("C:\\wall.png");
}

Wall::Wall(bool tag, float x, float y, float sizeX, float sizeY) : Figure(tag, x, y, sizeX, sizeY) //Конструктор с параметрами(tag, x, y, sizeX, sizeY)
{
    FigureImage = Image::FromFile("C:\\wall.png");
}

Wall::~Wall() //Деструктор
{
    ;
}