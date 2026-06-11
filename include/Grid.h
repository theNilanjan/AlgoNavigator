#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Grid
{
public:
    static const int ROWS = 20;
    static const int COLS = 20;
    static const int CELL_SIZE = 30;

    std::vector<std::vector<int>> cells;

    Grid();

    void draw(sf::RenderWindow& window);
};