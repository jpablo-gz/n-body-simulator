#ifndef CAMERA_HPP
#define CAMERA_HPP

// includes:
#include "lib/main.hpp"
#include "lib/3Dmath.hpp"

class Camera {
private:
    float fov, distance, nearPlane, farPlane;
    Vec eye;
    Vec target;
    Vec up{0, 1, 0};

public:

};

#endif // CAMERA_HPP