#include "unit.h"
#include <vector>
using std::vector;


class Grid{

    private:
        
        void buildMatrix(int width, int height, vector<sf::Color> colors, int windowSize);

    public:
        vector<vector<Unit>> unitMatrix;
        Grid(int width, int height, vector<sf::Color> colors, int windowSize);
        int getHeight();
        int getWidth();


};