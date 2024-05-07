#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "window.h"
#include "box.h"
#include "button.h"
#include "flag.h"
#include "numbers.h"
#include "mines.h"
#include "grid.h"
#include "menu.h"
#include "endscreen.h"

//prototipos

void click_flood(Box **cell, int size, int &i, int &j);
void easyGame(Box **&cell, int &grid_size, Mines &mines, Numbers &numbers, Flag &flag, Window &window, Grid &grid);
void mediumGame(Box **&cell, int &grid_size, Mines &mines, Numbers &numbers, Flag &flag, Window &window, Grid &grid);
void hardGame(Box **&cell, int &grid_size, Mines &mines, Numbers &numbers, Flag &flag, Window &window, Grid &grid);
void customGame(Box **&cell, int &grid_size, Mines &mines, Numbers &numbers, Flag &flag, Window &window, Grid &grid);
void startGame(Box **&cell, int &grid_size, Mines &mines, Numbers &numbers, Flag &flag, Window &window, Grid &grid, Menu &menu, bool &onGame);

int main() {
    Window window;
    window.setWindow();
    Menu menu;
    menu.startMenu();
    menu.startSettingsMenu();
    Grid grid;
    Flag flag;
    int grid_size = 0;
    Mines mines;
    Numbers numbers;
    Box **cell = nullptr;
    Endscreen endscreen;

    bool start_game = false;
    bool start_settings = false;
    bool onGame = false;
    bool lose_game = false;
    bool win_game = false;
    bool restart = false;
    bool main_menu = false;
    

    while (window.window.isOpen())
    {
        sf::Event event;
        while (window.window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.window.close();

                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        if (!lose_game && !win_game && start_game)
                        {
                            grid.click(sf::Mouse::getPosition(window.window), cell, grid_size, lose_game);
                        }
                        if (start_game && !onGame)
                        {
                            startGame(cell, grid_size, mines, numbers, flag, window, grid, menu, onGame);
                        }
                        else if (!onGame)
                        {
                            menu.menuButtons(sf::Mouse::getPosition(window.window), start_game, start_settings);
                            menu.settingsButtons(sf::Mouse::getPosition(window.window), start_settings, start_game);
                        }
                        if (lose_game || win_game)
                        {
                            endscreen.buttons(sf::Mouse::getPosition(window.window), restart, main_menu);
                        }
                    }
                    else if (event.mouseButton.button == sf::Mouse::Right && onGame && !lose_game && !win_game)
                    {
                        flag.click(sf::Mouse::getPosition(window.window), cell, grid_size);
                    }
                    break;

                default:
                    break;
            }
        }
        if (onGame)
        {
            win_game = grid.win(cell,mines,grid_size);
        }
        if (restart)
        {
            restart = false;
            lose_game = false;
            win_game = false;
            onGame = false;
            grid_size = 0;
            numbers.resetNumbers(cell, grid_size);
            flag.resetFlag();
            mines.resetMines(cell, grid_size);
            for(int i = 0; i < grid_size; ++i)
            {
                for(int j = 0; j < grid_size; ++j)
                {
                    cell[i][j].reset();
                }
            }
        }
        else if (main_menu)
        {
            main_menu = false;
            lose_game = false;
            win_game = false;
            onGame = false;
            start_game = false;
            grid_size = 0;
            numbers.resetNumbers(cell, grid_size);
            flag.resetFlag();
            mines.resetMines(cell, grid_size);
        }
            window.window.clear();
        if (start_game)
        {
            grid.gridDraw(cell, grid_size, window);
            flag.drawFlag(cell, grid_size, window);
        }
        else if (!start_game)
        {
            menu.drawMenu(window, start_settings);
        }
        if (lose_game || win_game)
        {
            endscreen.setEndscreen(window, lose_game, win_game);
            mines.drawMines(cell, grid_size, window);
            endscreen.draw(window);
        }
            window.window.display();
    }
    for(int i = 0; i < grid_size; ++i)
    {
        delete [] cell[i];
    }
    delete [] cell;

    return 0;
}

void easyGame(Box **&cell, int &grid_size, Mines &mines, Numbers &numbers, Flag &flag, Window &window, Grid &grid) {
    grid_size = 10;
    cell = new Box*[grid_size];
    for(int i = 0; i < grid_size; ++i)
        cell[i] = new Box[grid_size];

    mines.minas_totales = 10;
    mines.setMines(cell, grid_size);
    numbers.setNumbers(cell, grid_size);
    grid.setGrid(grid_size, cell, window);
    flag.setFlag(cell, grid_size);
}

void mediumGame(Box **&cell, int &grid_size, Mines &mines, Numbers &numbers, Flag &flag, Window &window, Grid &grid) {
    grid_size = 15;
    cell = new Box*[grid_size];
    for(int i = 0; i < grid_size; ++i)
        cell[i] = new Box[grid_size];

    mines.minas_totales = 30;
    mines.setMines(cell, grid_size);
    numbers.setNumbers(cell, grid_size);
    grid.setGrid(grid_size, cell, window);
    flag.setFlag(cell, grid_size);
}

void hardGame(Box **&cell, int &grid_size, Mines &mines, Numbers &numbers, Flag &flag, Window &window, Grid &grid) {
    grid_size = 20;
    cell = new Box*[grid_size];
    for(int i = 0; i < grid_size; ++i)
        cell[i] = new Box[grid_size];

    mines.minas_totales = 50;
    mines.setMines(cell, grid_size);
    numbers.setNumbers(cell, grid_size);
    grid.setGrid(grid_size, cell, window);
    flag.setFlag(cell, grid_size);
}

void customGame(Box **&cell, int &grid_size, Mines &mines, Numbers &numbers, Flag &flag, Window &window, Grid &grid) {
    do{
        std::cout << "Elije el tamaño del grid 5-20" << std::endl;
        std::cin >> grid_size;
    } while (grid_size < 5 || grid_size > 20);

    cell = new Box*[grid_size];
    for(int i = 0; i < grid_size; ++i)
        cell[i] = new Box[grid_size];

    int max_mines = (grid_size*grid_size) - 1;
    do{
        std::cout << "Elije el numero de minas 1-" << max_mines << std::endl;
        std::cin >> mines.minas_totales;
    } while (mines.minas_totales < 1 || mines.minas_totales > max_mines);
    mines.setMines(cell, grid_size);
    numbers.setNumbers(cell, grid_size);
    grid.setGrid(grid_size, cell, window);
    flag.setFlag(cell, grid_size);

}

void click_flood(Box **cell, int size, int &i, int &j) {
    if (cell[i][j].close_mines == 0) {
        // Arriba
        if (i > 0) //checar limites del grid para que no pase el stack overflow o agarre algun cell[-1][-1] por ejemplo
            cell[i - 1][j].click();

        // Izquierda
        if (j > 0)
            cell[i][j - 1].click();

        // Abajo
        if (i < size - 1)
            cell[i + 1][j].click();

        // Derecha
        if (j < size - 1)
            cell[i][j + 1].click();

        // Arriba izquierda
        if (i > 0 && j > 0)
            cell[i - 1][j - 1].click();

        // Arriba derecha
        if (i > 0 && j < size - 1)
            cell[i - 1][j + 1].click();

        // Abajo izquierda
        if (i < size - 1 && j > 0)
            cell[i + 1][j - 1].click();

        // Abajo derecha
        if (i < size - 1 && j < size - 1)
            cell[i + 1][j + 1].click();
    }
}

void flood(Box **cell, int size, int &x_pos, int &y_pos) {
    int i = x_pos, j = y_pos;
    if (cell[x_pos][y_pos].close_mines == 0)
    {
        // Arriba
        while (i > 0)
        {
            click_flood(cell, size, i, j);
            i -= 1;
            if (cell[i][j].close_mines > 0 || i  == 0)
            {
                i = x_pos;
                break;
            }
        }

        // Izquierda
        while (j > 0)
        {
            click_flood(cell, size, i, j);
            j -= 1;
            if (cell[i][j].close_mines > 0 || j == 0)
            {
                j = y_pos;
                break;
            }
        }

        // Abajo
        while (i < size - 1)
        {
            click_flood(cell, size, i, j);
            i += 1;
            if (cell[i][y_pos].close_mines > 0 || i == size - 1)
            {
                i = x_pos;
                break;
            }
        }

        // Derecha
        while (j < size - 1)
        {
            click_flood(cell, size, i, j);
            j += 1;
            if (cell[x_pos][j].close_mines > 0 || j == size - 1)
            {
                j = y_pos;
                break;
            }
        }

        // Arriba izquierda
        while (i > 0 && j > 0)
        {
            click_flood(cell, size, i, j);
            i -= 1;
            j -= 1;
            if (cell[i][j].close_mines > 0 || i == 0 || j == 0)
            {
                i = x_pos;
                j = y_pos;
                break;
            }
        }

        // Arriba derecha
        while (i > 0 && j < size - 1)
        {
            click_flood(cell, size, i, j);
            i -= 1;
            j += 1;
            if (cell[i][j].close_mines > 0 || i == 0 || j == size - 1)
            {
                i = x_pos;
                j = x_pos;
                break;
            }
        }

        // Abajo izquierda
        while (i < size - 1 && j > 0)
        {
            click_flood(cell, size, i, j);
            i += 1;
            j -= 1;
            if (cell[i][j].close_mines > 0 || i == size - 1 || j == 0)
            {
                i = x_pos;
                j = y_pos;
                break;
            }
        }

        // Abajo derecha
        while (i < size - 1 && j < size - 1)
        {
            click_flood(cell, size, i, j);
            i += 1;
            j += 1;
            if (cell[i][j].close_mines > 0 || i == size - 1 || j == size - 1)
            {
                i = x_pos;
                j = y_pos;
                break;
            }
        }
    }
}

void startGame(Box **&cell, int &grid_size, Mines &mines, Numbers &numbers, Flag &flag, Window &window, Grid &grid, Menu &menu, bool &onGame) {
    if (menu.options == 0 && !onGame)
    {
        easyGame(cell, grid_size, mines, numbers, flag, window, grid);
    }
    else if (menu.options == 1 && !onGame)
    {
        mediumGame(cell, grid_size, mines, numbers, flag, window, grid);
    }
    else if (menu.options == 2 && !onGame)
    {
        hardGame(cell, grid_size, mines, numbers, flag, window, grid);
    }
    else if (menu.options == 3 && !onGame)
    {
        customGame(cell, grid_size, mines, numbers, flag, window, grid);
    }

    mines.setMineTexture(cell, grid_size);
    onGame = true;
}
