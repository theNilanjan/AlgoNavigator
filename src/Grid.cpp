#include "../include/Grid.h"

Grid::Grid()
{
    cells.resize(ROWS, std::vector<int>(COLS, 0));
}

void Grid::draw(sf::RenderWindow& window)
{
    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            sf::RectangleShape rect(
                sf::Vector2f(CELL_SIZE - 1,
                             CELL_SIZE - 1));

            rect.setPosition(
                sf::Vector2f(
                    col * CELL_SIZE,
                    row * CELL_SIZE));

          if(cells[row][col] == 0)
    rect.setFillColor(sf::Color::White);

else if(cells[row][col] == 1)
    rect.setFillColor(sf::Color::Black);

else if(cells[row][col] == 2)
    rect.setFillColor(sf::Color::Green);

else if(cells[row][col] == 3)
    rect.setFillColor(sf::Color::Red);

else if(cells[row][col] == 4)
    rect.setFillColor(sf::Color::Blue);

else if(cells[row][col] == 5)
    rect.setFillColor(sf::Color::Yellow);

            window.draw(rect);
        }
    }
}