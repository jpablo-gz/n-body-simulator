#ifndef MAIN_HPP
#define MAIN_HPP

// includes:
#include "external/SFML-3.1.0/include/SFML/Graphics.hpp"

// Variables globales:
const unsigned int ANCHO = 800;
const unsigned int ALTO = 600;

// ajustes para camara:
const 

// buffer principal de pixeles
extern sf::Image imagebuffer;

// Función para actualizar la pantalla con el contenido del buffer de pixeles.
// w = window, t = texture, s = sprite
void updateScreen(sf::RenderWindow& w, sf::Texture& t, const sf::Sprite& s){
    t.update(imagebuffer);

    w.clear(sf::Color::Black);
    w.draw(s);
    w.display();
}

#endif // MAIN_HPP