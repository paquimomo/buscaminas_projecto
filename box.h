//
// Created by paxo on 06/05/2024.
//

#ifndef BUSCAMINAS_BOX_H
#define BUSCAMINAS_BOX_H

class Box {
private:
    bool mines = false;
    bool clicked = false;
    bool rightclick = false;
public:
    sf::RectangleShape square;
    int close_mines = 0;
    sf::Text number;
    sf::Font font;
    sf::Sprite flag;
    sf::Sprite mine;
    bool active_flag = false;

    void setFont() {
        if (!font.loadFromFile("C:/Windows/fonts/arial.ttf")) {
            // Si no se pudo cargar la fuente, mostrar un mensaje de error
            std::cerr << "Error al cargar la fuente" << std::endl;
        }
        number.setFont(font);
    }

    void setSquare(float x) {
        square.setSize(sf::Vector2f(x, x));
        square.setFillColor(sf::Color(192, 192, 192));
        square.setOutlineColor(sf::Color(128, 128, 128));
        square.setOutlineThickness(2);
    }

    void setMine() {
        this->mines = true;
    }

    bool getMine() const {
        return mines;
    }

    void click() {
        this->clicked = true;
    }

    bool getClick() {
        return clicked;
    }

    void rightClick(bool active) {
        if (active)
        {
            this->rightclick = false;
        }
        else{
            this->rightclick = true;
        }
    }

    bool getRightClick() {
        return rightclick;
    }

    void reset() {
        mines = false;
        clicked = false;
        rightclick = false;
        active_flag = false;
        close_mines = 0;
        square.setSize(sf::Vector2f(0, 0));
        number.setString("");
    }

};

#endif //BUSCAMINAS_BOX_H
