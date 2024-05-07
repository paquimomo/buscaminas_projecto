//
// Created by paxo on 06/05/2024.
//

#ifndef BUSCAMINAS_BUTTON_H
#define BUSCAMINAS_BUTTON_H

class Button {
public:
    sf::Text text;
    sf::RectangleShape rectangle;
    sf::Font font;
    bool clicked = false;

    void createButton(std::string string, sf::Vector2f size, int x_pos, int y_pos, sf::Color color){
        font.loadFromFile("C:/Windows/fonts/arial.ttf");

        text.setFont(font);
        text.setString(string);
        text.setPosition(x_pos, y_pos);
        rectangle.setSize(size);
        rectangle.setPosition(x_pos, y_pos);
        rectangle.setFillColor(color);
    }

    void drawButton(Window &window) {
        window.window.draw(rectangle);
        window.window.draw(text);
    }

    void click(sf::Vector2i mousePos) {
        if (rectangle.getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            clicked = true;
        }
    }
};

#endif //BUSCAMINAS_BUTTON_H
