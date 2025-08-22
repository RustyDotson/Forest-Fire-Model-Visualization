#include "grid.h"
#include <iostream>
using std::cout, std::endl;


Grid::Grid(int width, int height, vector<sf::Color> colors){
    unitMatrix = {};
    buildMatrix(width, height, colors);
}

void Grid::buildMatrix(int width, int height, vector<sf::Color> colors){
    vector<Unit> row;
    for(int wCounter=0; wCounter<width; wCounter++){
        row = vector<Unit> {};
        for(int hCounter=0; hCounter<height; hCounter++){
            row.push_back(Unit(0, wCounter, hCounter, colors));
        }
        unitMatrix.push_back(row);
    }
}

int Grid::getHeight(){
    return unitMatrix.size();
}

int Grid::getWidth(){
    return unitMatrix[0].size();
}


//Below is a testable main function that can be used to test just the grid class.

/*int main(){
    Unit test(0, 0, 0);
    Grid testGrid(10, 10);
    cout << test.getLocation()[0] << endl;
    return 0;
}*/
