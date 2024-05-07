//
// Created by paxo on 06/05/2024.
//

#ifndef BUSCAMINAS_MINES_H
#define BUSCAMINAS_MINES_H

class Mines { //crear el sprite de la mina
public:
    int minas_totales;
    sf::Texture texture;
    void setMines(Box **&cell, int size) {
        std::srand(std::time(0));
        for (int i = 0; i < minas_totales; ++i)
        {
            int aleatorio = std::rand() % size;
            int aleatorio2 = std::rand() % size;
            while (cell[aleatorio][aleatorio2].getMine()){
                aleatorio = std::rand() % size;
                aleatorio2 = std::rand() % size;
            }

            cell[aleatorio][aleatorio2].setMine();
        }
    }

    void setMineTexture(Box **cell, int &size) {
        texture.loadFromFile("C:\\Users\\paxo\\Desktop\\buscaminas\\mine.png");

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (cell[i][j].getMine())
                {
                    cell[i][j].mine.setTexture(texture);
                    cell[i][j].mine.setPosition(cell[i][j].square.getPosition().x, cell[i][j].square.getPosition().y);
                    cell[i][j].mine.setScale(0.1f, 0.1f);
                }
            }
        }
    }

    void drawMines(Box **cell, int &size, Window &window) {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (cell[i][j].getMine())
                {
                    window.window.draw(cell[i][j].mine);
                    cell[i][j].square.setFillColor(sf::Color::Red);
                }
            }
        }
    }

    void resetMines(Box **cell, int &size) {
        minas_totales = 0;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                cell[i][j].close_mines = 0;
            }
        }
        texture = sf::Texture();
    }

};

#endif //BUSCAMINAS_MINES_H
