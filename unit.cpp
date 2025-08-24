#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "unit.h"
using std::vector, std::cout, std::endl, std::srand, std::time;


Unit::Unit(int status, int col, int row, vector<sf::Color> colors){
    //below line is for square shape:
    unitShape.setSize(sf::Vector2f(3.f, 3.f));

    //below line is for circle shape:
    //unitShape.setRadius(4.f);

    unitStatus = status;
    unitColumn = col;
    unitRow = row;
    unitShape.move({unitColumn*3.f, unitRow*3.f});
    setColor(colors[1]);


    cout << "initialized unit for location x(" << col << "), y(" << row << ")." << endl;
}


vector<int> Unit::getLocation(){
    return {unitColumn, unitRow};
}


void Unit::setColor(sf::Color color){
    unitShape.setFillColor(color);
}

//Below is a testable main function that can be used to test just the unit class.

/*int main(){
    Unit test(0, 0, 0);
    cout << test.getLocation()[0] << endl;
    return 0;
}*/