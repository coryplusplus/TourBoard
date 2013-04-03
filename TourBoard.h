#include <vector>
#include "c_Square.h"



class TourBoard{

public:
    TourBoard(const int &w, const int &l);

    void printBoard();

    void travelRight(c_Square &square);

    void travelLeft(c_Square &square);

    void travelUp(c_Square &square);

    void travelDown(c_Square &square);

    void travel(c_Square &square, int moves_count, std::string path);

    bool firstRowVisited();

    bool checkAbove(c_Square &square);

    bool checkRight(c_Square &square);

    bool checkLeft(c_Square &square);

    std::vector<std::vector<c_Square> > board; 

    int moves;
    
    int solutions;

    int length;

    int width;

    int checkRightCount;
    int checkAboveCount;

private:




};
