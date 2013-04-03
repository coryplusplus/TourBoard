#include "TourBoard.h"
#include <time.h>
#include <fstream>
#include <sstream>


ofstream myfile;

TourBoard::TourBoard(const int &w, const int &l)
{
    moves = l * w;
    length = l;
    width = w;
    solutions = 0;
    int square_id = 0;
    for(int x = 0; x < length; x++)
    {
        vector<c_Square> row;
        for(int y = 0; y < width; y++)
        {
            c_Square square(x,y, length, width, square_id);
            square_id++;
            row.push_back(square); 
        }
        board.push_back(row);

    }
}

void TourBoard::printBoard()
{
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.at(i).size(); j++)
        {
             cout<<" x";board.at(i).at(j).printXY();
        }

    cout<<endl;

    }
}

//if square above has not been visited we can throw this path away.
bool TourBoard::checkAbove(c_Square &square)
{
    if(square.position.x != 0 && board.at(square.position.x - 1).at(square.position.y).visited == false)
    {
        return false;
    }
    else
        return true;

}

//if square to the right has not been visited we can throw this path away.
bool TourBoard::checkRight(c_Square &square)
{
    if(square.position.y != (width - 1) && board.at(square.position.x).at(square.position.y + 1).visited == false)
    {
        return false;
    }
    else
        return true;

}

//if square to the left has not been visited we can throw this path away.
bool TourBoard::checkLeft(c_Square &square)
{
    if(square.position.y != 0 && board.at(square.position.x).at(square.position.y - 1).visited == false)
    {
        return false;
    }
    else
        return true;

}

void TourBoard::travel(c_Square &square, int moves_count, std::string path)
{
    if(square.visited)
    {
        return;
    }

    if(moves_count == 1 && square.position.x == (length - 1) and square.position.y == 0)
    {
        myfile<<path<<" ";
        myfile<<"\n";
        solutions++;
        return;
    }
    if(board.at(length - 1).at(0).visited)
    {
       return;
    }

    if(square.position.y == (width - 1) || square.position.y == 0)
    {
        if(!checkAbove(square))
            return;
    }
    if(square.position.x == (length - 1))
    {
        if(!checkRight(square))
            return;

    }
    if(square.position.x == 0)
    {
        if(!checkLeft(square))
            return;

    }

    ostringstream convert;
    convert<<square.id;
    path = path + " " + convert.str();
    square.visited = true;


    if(square.moveRight)
    {
        travel(board.at(square.right.x).at(square.right.y), moves_count - 1, path);
    }
    if(square.moveLeft)
    {
        travel(board.at(square.left.x).at(square.left.y),moves_count - 1, path);
        
    }
    if(square.moveDown)
    {
        travel(board.at(square.down.x).at(square.down.y), moves_count - 1, path);
    }
    if(square.moveUp)
    {
        travel(board.at(square.up.x).at(square.up.y), moves_count - 1, path);
    }
    square.visited = false;
    

}

int main()
{
    myfile.open ("solutions.txt");
    int x;
    int y;
    cout<<"Please enter board dimensions"<<endl;
    cout<<"X:";cin>>x;cout<<endl;
    cout<<"Y:";cin>>y;cout<<endl;
    clock_t tStart = clock();
    TourBoard board(x,y);
    board.printBoard();
    board.travel(board.board.at(0).at(0), board.moves,"");
    cout<<"There are "<<board.solutions<<" possible solutions"<<endl;
    cout<<"Time taken: "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<" seconds "<<endl;
    myfile.close();
    return 0;
}
