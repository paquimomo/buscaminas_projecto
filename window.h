//
// Created by paxo on 06/05/2024.
//

#ifndef BUSCAMINAS_WINDOW_H
#define BUSCAMINAS_WINDOW_H

class Window {
public:
    sf::RenderWindow window;

    void setWindow(){
        window.create(sf::VideoMode(900, 900),"Buscaminas",sf::Style::Titlebar | sf::Style::Close);
    }
};

#endif //BUSCAMINAS_WINDOW_H
