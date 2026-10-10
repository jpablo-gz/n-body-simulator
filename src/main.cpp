#include <SFML/Graphics.hpp>
#include "Rasterizer.hpp"

int main()
{
    constexpr unsigned int width = 800;
    constexpr unsigned int height = 600;

    sf::RenderWindow window(
        sf::VideoMode({width, height}),
        "N-Body Simulator",
        sf::Style::Titlebar | sf::Style::Close
    );

    window.setVerticalSyncEnabled(true);

    // Búfer de píxeles en la memoria de la computadora.
    sf::Image framebuffer(
        {width, height},
        sf::Color(0, 0, 0)
    );

    // Modificar un píxel de la imagen (ejemplo).
    Vec2D ubi = {400, 200};
    Color blanco = {250, 250, 250};
    putPixel(framebuffer, ubi, blanco);

    // Textura que permitirá presentar nuestro búfer.
    sf::Texture texture(framebuffer);

    // Un único sprite representa la imagen completa.
    sf::Sprite screen(texture);

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (const auto* key =
                    event->getIf<sf::Event::KeyPressed>())
            {
                if (key->code == sf::Keyboard::Key::Escape)
                {
                    window.close();
                }
            }
        }

        if (!window.isOpen())
            break;

        // Transferir los píxeles de la imagen a la textura.
        texture.update(framebuffer);

        // Presentar la imagen completa.
        window.clear(sf::Color::Black);
        window.draw(screen);
        window.display();
    }

    return 0;
}