#ifndef RASTERIZER_HPP
#define RASTERIZER_HPP

// includes:
#include "3Dmath.hpp"
#include <SFML/Graphics.hpp>

// estructura sencilla para empaquetar colores
struct Color{
    int r;
    int g;
    int b;
};

// colorear cordenada/pixel en pantalla por algun color
inline void putPixel(sf::Image& buffer, Vec coords, Color col) {
    const auto size = buffer.getSize();

    if (coords.x < 0 || coords.x >= size.x) return;
    if (coords.y < 0 || coords.y >= size.y) return;

    buffer.setPixel(
        {static_cast<unsigned int>(coords.x), static_cast<unsigned int>(coords.y)},
        sf::Color(col.r, col.g, col.b)
    );
}

#endif //RASTERIZER_HPP