#include <SFML/Graphics.hpp>
#include <vector>

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

        Unit(int status, int col, int row, std::vector<sf::Color> colors, float unitSize);

        ~Unit() = default;

        std::vector<int> getLocation();

        void setColor(sf::Color color);

};