// includes:
#include "object.hpp"

// clase objeto ----------------------------------------------------------------------------
Object::Object(Vec p, double r, Vec v){
    position = p.get_2D();
    radius = r;
    velocity = v.get_2D();

    // mass = surfaceDensity * PI * radius * radius
    mass = (1.0)*(3.1416)*(radius*radius);
}

// getters:
Vec Object::getPosition() const {
    return position;
}

Vec Object::getVelocity() const {
    return velocity;
}

double Object::getMass() const {
    return mass;
}

double Object::getRadius() const {
    return radius;
}

// setters:
void Object::setPosition(Vec& p) {
    position = p.get_2D();
}

void Object::setVelocity(Vec& v) {
    velocity = v.get_2D();
}

void Object::setRadius(double r) {
    if (r > 0){
        radius = r;
    }
}
