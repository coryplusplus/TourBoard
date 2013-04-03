#include <iostream>

using namespace std;

class c_Square {
public:

struct location{
int x;
int y;
};

c_Square(const int &x_pos, const int &y_pos, const int &length, const int &width, const int &ID);

void printXY();

void addPositions();

void setRules(const int &length, const int &width);

bool visited;
location position;
location up;
location down;
location left;
location right;

bool moveRight;
bool moveLeft;
bool moveUp;
bool moveDown;
int id;

private:



};
