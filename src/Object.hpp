#ifndef OBJECT_H
#define OBJECT_H

#include "3Dmath.hpp"

// clase objeto ----------------------------------------------------------------------------
class Object{
private:
    // parametros:
    Vec position;
    Vec velocity;
    double radius;
    double mass;

public:
    // constructor:
    Object(Vec p, double r, Vec v);

    // metodos:
    Vec getPosition() const;
    Vec getVelocity() const;
    double getMass() const;
    double getRadius() const;

    void setPosition(Vec& p);
    void setVelocity(Vec& v);
    void setRadius(double r);
};

#endif //OBJECT_H