#include "grid.h"
#include <iostream>
#include <vector>


Grid::Grid(int width, int height, std::vector<sf::Color> colors, int windowSize){
    unitMatrix = {};
    buildMatrix(width, height, colors, windowSize);
}

void Grid::buildMatrix(int width, int height, std::vector<sf::Color> colors, int windowSize){
    std::vector<Unit> row;
    float unitSize = windowSize / width;
    for(int wCounter=0; wCounter<width; wCounter++){
        row = std::vector<Unit> {};
        for(int hCounter=0; hCounter<height; hCounter++){
            row.push_back(Unit(0, wCounter, hCounter, colors, unitSize));
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

