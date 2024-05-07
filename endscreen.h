//
// Created by paxo on 07/05/2024.
//

#ifndef BUSCAMINAS_ENDSCREEN_H
#define BUSCAMINAS_ENDSCREEN_H

class Endscreen {
public:
    sf::RectangleShape rectangle;
    sf::Text text;
    sf::Font font;
    Button restart_button;
    Button main_menu_button;

    void setEndscreen(Window &window, bool &lose_game, bool &win_game)
    {
        if (!font.loadFromFile("C:/Windows/fonts/arial.ttf")) {
            std::cerr << "Error cargando la fuente\n";
        }
        rectangle.setSize(sf::Vector2f(300, 200));
        rectangle.setFillColor(sf::Color(240, 240, 240));
        rectangle.setPosition(window.window.getSize().x / 2 - rectangle.getSize().x / 2, window.window.getSize().y / 2 - rectangle.getSize().y / 2);
        rectangle.setOutlineThickness(2);
        rectangle.setOutlineColor(sf::Color::Black);
        rectangle.setOutlineThickness(2);
        rectangle.setOutlineColor(sf::Color::Black);

        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);
        if (lose_game)
        {
            text.setString("Game over");
            text.setFillColor(sf::Color::Red);
        }
        else if (win_game)
        {
            text.setString("You win");
            text.setFillColor(sf::Color::Green);
        }
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
        text.setPosition(rectangle.getPosition().x + rectangle.getSize().x / 2.0f,
                         rectangle.getPosition().y + rectangle.getSize().y / 4.0f);

        restart_button.createButton("Restart", sf::Vector2f(100, 50), rectangle.getPosition().x + 20, rectangle.getPosition().y + 120, sf::Color(30, 144, 255));
        main_menu_button.createButton("Menu", sf::Vector2f(100, 50), rectangle.getPosition().x + 180, rectangle.getPosition().y + 120, sf::Color(255, 69, 0));
    }

    void draw(Window &window)
    {
        window.window.draw(rectangle);
        window.window.draw(text);
        restart_button.drawButton(window);
        main_menu_button.drawButton(window);
    }

    void buttons(sf::Vector2i mousePos, bool &restart, bool &main_menu) {
        restart_button.click(mousePos);
        main_menu_button.click(mousePos);

        if (restart_button.clicked)
        {
            restart = true;
            restart_button.clicked = false;
        }
        else if (main_menu_button.clicked)
        {
            main_menu = true;
            main_menu_button.clicked = false;
        }
    }
};

#endif //BUSCAMINAS_ENDSCREEN_H
