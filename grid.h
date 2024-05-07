//
// Created by paxo on 06/05/2024.
//

#ifndef BUSCAMINAS_GRID_H
#define BUSCAMINAS_GRID_H

void flood(Box **cell, int size, int &x_pos, int &y_pos);
class Grid {
public:
    int no_mines;
    void setGrid(int size, Box **&cell, Window &window){
        float square_size = (window.window.getSize().x / size) - 6*(size-1) / size;
        float text_size = (window.window.getSize().x / size) - 6*(size-1) / size;

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                cell[i][j].setSquare(square_size);
                cell[i][j].square.setPosition(square_size*j + j*5, square_size*i + i*5);
                cell[i][j].setFont();
                cell[i][j].number.setCharacterSize(text_size);
                cell[i][j].number.setPosition(text_size*j + j*5, text_size*i + i*5);
                cell[i][j].number.setString(std::to_string(cell[i][j].close_mines));
                if (cell[i][j].close_mines == 1)
                {
                    cell[i][j].number.setFillColor(sf::Color::Blue);
                }
                else if (cell[i][j].close_mines == 2)
                {
                    cell[i][j].number.setFillColor(sf::Color::Green);
                }
                else if (cell[i][j].close_mines > 3)
                {
                    cell[i][j].number.setFillColor(sf::Color::Red);
                }
                else{
                    cell[i][j].number.setFillColor(sf::Color::Blue);
                }
            }
        }
    }

    void gridDraw(Box **cell, int size, Window &window) {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                window.window.draw(cell[i][j].square);
                if (cell[i][j].getClick() && !cell[i][j].getMine())
                {
                    cell[i][j].square.setFillColor(sf::Color(169, 169, 169));
                    if (cell[i][j].close_mines != 0)
                    {
                        window.window.draw(cell[i][j].number);
                    }
                }
                else if (cell[i][j].getRightClick())
                {
                    window.window.draw(cell[i][j].flag);
                }
            }
        }
    }

    void click(sf::Vector2i mousePos, Box **cell, int size, bool &lose_game) {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (cell[i][j].square.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    if (!cell[i][j].getClick())
                    {
                        cell[i][j].click();
                        flood(cell, size, i, j);
                    }
                    if (cell[i][j].getMine())
                    {
                        lose_game = true;
                    }
                }
            }
        }
    }

    bool win(Box **cell,Mines mine, int &size) {
        no_mines = size*size - mine.minas_totales;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (!cell[i][j].getMine() && cell[i][j].getClick())
                {
                    no_mines--;
                }
            }
        }
        if (no_mines == 0)
        {
            return true;
        }
        else{
            return false;
        }
    }

};

#endif //BUSCAMINAS_GRID_H
