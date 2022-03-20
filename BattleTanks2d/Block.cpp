#include "Block.h"
Block::Block()//Конструктор
{

}
Block::Block(float x, float y, float sizeX, float sizeY) : Figure(x, y, sizeX, sizeY) //Конструктор с параметрами(x, y, sizeX, sizeY)
{
    FigureImage = Image::FromFile("C:\\block.png");
}

Block::Block(bool tag, float x, float y, float sizeX, float sizeY) : Figure(tag, x, y, sizeX, sizeY) //Конструктор с параметрами(tag, x, y, sizeX, sizeY)
{
    FigureImage = Image::FromFile("C:\\block.png");
}

Block::~Block() //Деструктор
{
    ;
}