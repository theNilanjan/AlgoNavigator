#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Grid.h"
#include "../include/Pathfinding.h"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({600, 600}),
        "Pathfinding Visualizer"
    );

    Grid grid;

    bool placingStart = false;
    bool placingEnd = false;

    int startRow = -1;
    int startCol = -1;

    int endRow = -1;
    int endCol = -1;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (const auto* keyPressed =
                event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::S)
                {
                    placingStart = true;
                    placingEnd = false;
                    std::cout << "S pressed\n";
                }

                if (keyPressed->code == sf::Keyboard::Key::E)
                {
                    placingEnd = true;
                    placingStart = false;
                    std::cout << "E pressed\n";
                }

                if (keyPressed->code == sf::Keyboard::Key::B)
                {
                    if (startRow != -1 &&
                        endRow != -1)
                    {
                        Pathfinding::BFS(
                            grid.cells,
                            startRow,
                            startCol,
                            endRow,
                            endCol
                        );

                        std::cout << "BFS started\n";
                    }
                }
            }
        }

        // LEFT CLICK
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            sf::Vector2i mousePos =
                sf::Mouse::getPosition(window);

            int col = mousePos.x / Grid::CELL_SIZE;
            int row = mousePos.y / Grid::CELL_SIZE;

            if (row >= 0 &&
                row < Grid::ROWS &&
                col >= 0 &&
                col < Grid::COLS)
            {
                if (placingStart)
                {
                    grid.cells[row][col] = 2;

                    startRow = row;
                    startCol = col;

                    placingStart = false;

                    std::cout << "Start placed\n";
                }
                else if (placingEnd)
                {
                    grid.cells[row][col] = 3;

                    endRow = row;
                    endCol = col;

                    placingEnd = false;

                    std::cout << "End placed\n";
                }
                else
                {
                    grid.cells[row][col] = 1;
                }
            }
        }

        // RIGHT CLICK
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        {
            sf::Vector2i mousePos =
                sf::Mouse::getPosition(window);

            int col = mousePos.x / Grid::CELL_SIZE;
            int row = mousePos.y / Grid::CELL_SIZE;

            if (row >= 0 &&
                row < Grid::ROWS &&
                col >= 0 &&
                col < Grid::COLS)
            {
                grid.cells[row][col] = 0;
            }
        }

        window.clear();

        grid.draw(window);

        window.display();
    }

    return 0;
}