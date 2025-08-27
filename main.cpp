#include <SFML/Graphics.hpp>
#include "grid.h"
#include <ctime>
#include <unistd.h>


sf::Color brown(150,75,0);
/*colors is a vector of sf::colors that are used 
for the three different colors for trees, land, and fire. 
colors[0] == a tree, 
[1] == the ground color, 
and [2] == the color for fire.
*/
vector<sf::Color> colors = {sf::Color::Green, sf::Color::Black, sf::Color::Red, sf::Color::Yellow};

void drawGrid(sf::RenderWindow& window, Grid grid){
    /*
    draws the entire grid to sfml graphics. 
    NOTICE: this does not automatically update the window. 
    window.display() must be run in order to visually update the screen.

    The commented code example below will clear all window contents, 
    write the new grid, and display the new content to the window:

    window.clear();
    drawGrid(window, grid);
    window.display();
    */
    for(int wCounter=0; wCounter<grid.getWidth(); wCounter++){
        for(int hCounter=0; hCounter<grid.getHeight(); hCounter++){
            window.draw(grid.unitMatrix[wCounter][hCounter].unitShape);
        }
    }
}

void drawUnit(sf::RenderWindow& window, Grid grid, int x, int y){
    //redraws unit at grid coordinates x, y.
    window.draw(grid.unitMatrix[x][y].unitShape);
}


void burnTrees(Grid &grid, int startX, int startY, sf::RenderWindow &window){
    //performs the breadth-first search burning function on the grid.
    std::queue<std::pair<int, int>> fireQueue;
    std::queue<std::pair<int, int>> colorEffectQueue;


    fireQueue.push({startX, startY});

    while(!fireQueue.empty()){
        auto [fireUnitX, fireUnitY] = fireQueue.front();
        fireQueue.pop();

        if (grid.unitMatrix[fireUnitX][fireUnitY].unitShape.getFillColor() != colors[0]){
            continue;
        }

        grid.unitMatrix[fireUnitX][fireUnitY].setColor(colors[2]);
        colorEffectQueue.push({fireUnitX, fireUnitY});

        drawUnit(window, grid, fireUnitX, fireUnitY);
        window.display();

        //coordinates for all of the surrounding units
        const int dx[] = {-1, 1, 0, 0, 1, -1, 1, -1};
        const int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

        int nx;
        int ny;

        for (int i=0; i<8; ++i){
            nx = dx[i] + fireUnitX;
            ny = dy[i] + fireUnitY;

            if(nx > 0 
                && nx < grid.unitMatrix.size()-1 
                && ny > 0 
                && ny < grid.unitMatrix[0].size()-1){
                fireQueue.push({nx, ny});
            }
        }

    }

    while(!colorEffectQueue.empty()){
        auto [x, y] = colorEffectQueue.front();
        colorEffectQueue.pop();
        grid.unitMatrix[x][y].setColor(colors[1]);

    }

}


int main()
{   
    std::srand(std::time(0));
    //windowSize determines the size of the window being used.
    unsigned int windowSize = 800;
    sf::RenderWindow window(sf::VideoMode({windowSize, windowSize}), "Forest Fire Visual Model");

    //gridSize determines the width and height of the grid.
    int gridSize = 20;
    Grid grid(gridSize, gridSize, colors, windowSize);

    int locationx = (rand() % grid.unitMatrix.size());
    int locationy = (rand() % grid.unitMatrix[0].size());

    //two random rolls for tree and lightning spawn (a random number between 1 and 100)
    int treeSpawnRoll = (rand() % 100);
    int lightningSpawnRoll = (rand() % 100);

    //the percent change that either a tree or lightning strikes.
    int treeSpawnChance = 35;
    int lightningStrikeChance = 3;

    while (window.isOpen())
    {  
        //usleep(20);
    
        treeSpawnRoll = (rand() % 100);
        lightningSpawnRoll = (rand() % 100);

        if (treeSpawnRoll < treeSpawnChance){
            while (grid.unitMatrix[locationx][locationy].unitShape.getFillColor() == colors[0]){
                locationx = (rand() % grid.unitMatrix.size());
                locationy = (rand() % grid.unitMatrix[0].size());
            }
            
            grid.unitMatrix[locationx][locationy].unitShape.setFillColor(colors[0]);
        }

        if (lightningSpawnRoll < lightningStrikeChance){
            locationx = (rand() % grid.unitMatrix.size());
            locationy = (rand() % grid.unitMatrix[0].size());
            if (grid.unitMatrix[locationx][locationy].unitShape.getFillColor() == colors[0]){
                burnTrees(grid, locationx, locationy, window);
            }
            grid.unitMatrix[locationx][locationy].unitShape.setFillColor(colors[2]);
            window.clear();
            drawGrid(window, grid);
            window.display();
            usleep(100);
            grid.unitMatrix[locationx][locationy].unitShape.setFillColor(colors[1]);
        }

        locationx = (rand() % grid.unitMatrix.size());
        locationy = (rand() % grid.unitMatrix[0].size());
        
        std::cout << locationx << ", " << locationy << std::endl;

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        drawGrid(window, grid);
        window.display();
    }
}