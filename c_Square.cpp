#include "c_Square.h"

c_Square::c_Square(const int &x_pos, const int &y_pos, const int &length, const int &width, const int &ID)
{
    visited = false;
    moveUp = false;
    moveDown = false;
    moveLeft = false;
    moveRight = false;
    position.x = x_pos;
    position.y = y_pos;
    id = ID;
    addPositions();
    setRules(length, width);
}

void c_Square::printXY()
{
    cout<<"(" << position.x << " " << position.y << ")";

}

void c_Square::addPositions()
{
    up.x = position.x - 1; 
    up.y = position.y;
    
    down.x = position.x + 1; 
    down.y = position.y;

    left.x = position.x;
    left.y = position.y - 1;

    right.x = position.x; 
    right.y = position.y + 1;
}

void c_Square::setRules(const int &length, const int &width)
{
    if(position.y != 0)
    {
        moveLeft = true;
    }
    if(position.x != 0)
    {
        moveUp = true;
    }
    if(position.y != width - 1)
    {
        moveRight = true;
    }
    if(position.x != length - 1)
    {
        moveDown = true;
    }
    if(length == 2 && width == 2 && position.y == 0)
    {
        moveDown = false;
    }

}
