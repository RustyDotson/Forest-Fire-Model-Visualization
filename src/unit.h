#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using std::vector;

class Unit {
    private:
        
        int unitStatus;
        int unitColumn;
        int unitRow;

    public:
        //use below line if you want a rectangle:
        sf::RectangleShape unitShape;

        //use below line if you want a circle:
        //sf::CircleShape unitShape;

        Unit(int status, int col, int row, vector<sf::Color> colors, float unitSize);

        ~Unit() = default;

        vector<int> getLocation();

        void setColor(sf::Color color);

};