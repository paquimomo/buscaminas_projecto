//
// Created by paxo on 06/05/2024.
//

#ifndef BUSCAMINAS_FLAG_H
#define BUSCAMINAS_FLAG_H

class Flag {
public:
    sf::Texture texture;

    void setFlag(Box **&cell, int &size) {
        if (!texture.loadFromFile("C:\\Users\\paxo\\Desktop\\buscaminas\\Flag-icon.png")) {
            std::cerr << "Error al cargar la textura" << std::endl;
            return;
        }
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                cell[i][j].flag.setTexture(texture);
                cell[i][j].flag.setPosition(cell[i][j].square.getPosition().x + 5, cell[i][j].square.getPosition().y + 5);
                cell[i][j].flag.setScale(0.1f, 0.1f);
            }
        }
    }

    void click(sf::Vector2i mousePos, Box **cell, int &size) {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (cell[i][j].square.getGlobalBounds().contains(mousePos.x, mousePos.y) && cell[i][j].active_flag && !cell[i][j].getClick())
                {
                    cell[i][j].rightClick(cell[i][j].active_flag);
                    cell[i][j].active_flag = false;
                }
                else if (cell[i][j].square.getGlobalBounds().contains(mousePos.x, mousePos.y) && !cell[i][j].active_flag && !cell[i][j].getClick())
                {
                    cell[i][j].rightClick(cell[i][j].active_flag);
                    cell[i][j].active_flag = true;
                }
            }
        }
    }

    void drawFlag(Box **cell, int size, Window &window) {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (cell[i][j].getRightClick())
                {
                    window.window.draw(cell[i][j].flag);
                }
            }
        }
    }

    void resetFlag() {
        texture = sf::Texture();
    }
};

#endif //BUSCAMINAS_FLAG_H
