//
// Created by paxo on 06/05/2024.
//

#ifndef BUSCAMINAS_MENU_H
#define BUSCAMINAS_MENU_H

class Menu {
public:
    Button start_button;
    Button settings_button;
    Button easy_button;
    Button medium_button;
    Button hard_button;
    Button custom_button;
    Button back_button;
    int options = 0;
    sf::Text title;
    sf::Font font;

    void startMenu() {
        start_button.createButton("Start game", sf::Vector2f(300, 60), 300, 200, sf::Color(0, 128, 128));
        settings_button.createButton("Settings", sf::Vector2f(300, 60), 300, 300, sf::Color(0, 128, 128));

        if (!font.loadFromFile("C:/Windows/fonts/arial.ttf")) {
            std::cerr << "Error al cargar la fuente" << std::endl;
            return;
        }
        title.setFont(font);
        title.setString("Buscaminas");
        title.setCharacterSize(80);
        title.setFillColor(sf::Color(0, 128, 128));
        title.setStyle(sf::Text::Bold);
        title.setPosition(250, 20);
    }


    void startSettingsMenu() {
        easy_button.createButton("Easy", sf::Vector2f(200, 60), 350, 150, sf::Color(0, 128, 128));
        medium_button.createButton("Medium", sf::Vector2f(200, 60), 350, 250, sf::Color(0, 128, 128));
        hard_button.createButton("Hard", sf::Vector2f(200, 60), 350, 350, sf::Color(0, 128, 128));
        custom_button.createButton("Custom", sf::Vector2f(200, 60), 350, 450, sf::Color(0, 128, 128));
        back_button.createButton("Back", sf::Vector2f(200, 60), 350, 550, sf::Color(0, 128, 128));
        easy_button.text.setCharacterSize(30);
        medium_button.text.setCharacterSize(30);
        hard_button.text.setCharacterSize(30);
        custom_button.text.setCharacterSize(30);
        back_button.text.setCharacterSize(30);
    }

    void menuButtons(sf::Vector2i mousePos, bool &start_game, bool &start_settings) {
        start_button.click(mousePos);
        settings_button.click(mousePos);
        if (start_button.clicked)
        {
            start_game = true;
            start_button.clicked = false;
        }
        if (settings_button.clicked)
        {
            start_settings = true;
            settings_button.clicked = false;
        }
    }

    void settingsButtons(sf::Vector2i  mousePos, bool &start_settings, bool &start_game) {
        easy_button.click(mousePos);
        medium_button.click(mousePos);
        hard_button.click(mousePos);
        custom_button.click(mousePos);
        back_button.click(mousePos);
        if (back_button.clicked)
        {
            back_button.clicked = false;
            start_settings = false;
            start_game = false;
        }

        if (easy_button.clicked)
        {
            options = 0;
            medium_button.clicked = false;
            hard_button.clicked = false;
            custom_button.clicked = false;
            easy_button.clicked = false;
        }
        else if (medium_button.clicked)
        {
            options = 1;
            easy_button.clicked = false;
            medium_button.clicked = false;
            hard_button.clicked = false;
            custom_button.clicked = false;
        }
        else if (hard_button.clicked)
        {
            options = 2;
            easy_button.clicked = false;
            medium_button.clicked = false;
            hard_button.clicked = false;
            custom_button.clicked = false;
        }
        else if (custom_button.clicked)
        {
            options = 3;
            easy_button.clicked = false;
            medium_button.clicked = false;
            hard_button.clicked = false;
            custom_button.clicked = false;
        }
    }


    void drawMenu(Window &window, bool &start_settings) {
        if (start_settings == true)
        {
            window.window.clear(sf::Color(220, 220, 220)); // Fondo gris claro

            window.window.draw(title);

            easy_button.drawButton(window);
            medium_button.drawButton(window);
            hard_button.drawButton(window);
            custom_button.drawButton(window);
            back_button.drawButton(window);
        }
        else if (start_settings == false)
        {
            window.window.clear(sf::Color(240, 240, 240)); // Fondo gris más claro

            window.window.draw(title);

            start_button.drawButton(window);
            settings_button.drawButton(window);
        }
    }
};

#endif //BUSCAMINAS_MENU_H
