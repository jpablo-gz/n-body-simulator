// includes:
#include "lib/main.hpp"

// Definición inicial del búfer de píxeles.
sf::Image imagebuffer({ANCHO, ALTO}, sf::Color::Black);

int main() {
    // Crea la ventana con el tamaño definido por ANCHO y ALTO.
    sf::RenderWindow window(
        sf::VideoMode({ANCHO, ALTO}),
        "N-Body Simulator",
        sf::Style::Titlebar | sf::Style::Close
    );

    window.setVerticalSyncEnabled(true);
    
    sf::Texture texture(imagebuffer);
    sf::Sprite screen(texture);

    // Bucle principal del programa
    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
                if (key->code == sf::Keyboard::Key::Escape) {
                    window.close();
                }
            }
        }

        if (!window.isOpen()) {
            break;
        }

        // Actualiza la pantalla
        updateScreen(window, texture, screen);
    }

    return 0;
}