#include "camera.hpp"
#include <cmath>

namespace Tyra {

    Camera::Camera(Pad* t_pad) :

        lookAt(0.0F),
        position(-2000.0F, 700.0F, -6000.0F),
        pad(t_pad),
        circleRotation(-5.0F),
        circleLength(30.0F),
        lookAtHeight(-4.0F) {}

    Camera::~Camera() {}

    void Camera::update() {

        updatePosition();
        updateLookAt();
    }

    void Camera::updatePosition() {

        const auto& leftJoy = pad->getLeftJoyPad();
        Vec4 direction(0.0F, 0.0F, 0.0F);

        if (leftJoy.v <= 100) {

            direction.x += unitCircle.x;
            direction.z += unitCircle.z;
        } 
        else if (leftJoy.v >= 200) {

            direction.x -= unitCircle.x;
            direction.z -= unitCircle.z;
        }

        if (leftJoy.h <= 100) {

            direction.x += unitCircle.z;
            direction.z -= unitCircle.x;
        } 
        else if (leftJoy.h >= 200) {

            direction.x -= unitCircle.z;
            direction.z += unitCircle.x;
        }

        float magnitude = std::sqrt(direction.x * direction.x + direction.z * direction.z);

        if (magnitude > 0) {

            direction.x /= magnitude;
            direction.z /= magnitude;

            position.x += direction.x * speed;
            position.z += direction.z * speed;

            speed = std::min(speed + acceleration, maxSpeed);

        }
        else {

            speed = std::max(speed - acceleration, minSpeed);
        }

        if (pad->getPressed().DpadUp) {

            position.y += 25;
        }
        else if (pad->getPressed().DpadDown) {
            
            position.y -= 25;
        }
    }

    void Camera::updateLookAt() {

        const float rotationOffset = 0.045F;
        const float heightOffset = 2.0F;
        
        const auto& rightJoy = pad->getRightJoyPad();

        if (rightJoy.h <= 100) {
            
            circleRotation += rotationOffset;
        }
        else if (rightJoy.h >= 200) {
            
            circleRotation -= rotationOffset;
        }

        if (rightJoy.v <= 100) {
            
            lookAtHeight += heightOffset;
        }
        else if (rightJoy.v >= 200) {
            
            lookAtHeight -= heightOffset;
        }

        unitCircle.x = Math::sin(circleRotation) * circleLength;
        unitCircle.y = lookAtHeight;
        unitCircle.z = Math::cos(circleRotation) * circleLength;

        lookAt = unitCircle + position;
    }
}