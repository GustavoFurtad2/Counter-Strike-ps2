#include "camera.hpp"

namespace Tyra {

    Camera::Camera(Pad* t_pad) :

        lookAt(0.0F),
        position(-2000.0F, 700.0F, -6000.0F),
        pad(t_pad),
        circleRotation(-5.0F),
        circleLength(30.0F),
        speed(20.0F),
        lookAtHeight(-4.0F) {}

    Camera::~Camera() {

    }

    void Camera::update() {
        updatePosition();
        updateLookAt();
    }

    void Camera::updatePosition() {

        const auto& leftJoy = pad->getLeftJoyPad();

        auto direction = Vec4(unitCircle).getNormalized() * speed;

        if (leftJoy.v <= 100) {

            position.x += direction.x;
            position.z += direction.z;

        }
        else if (leftJoy.v >= 200) {

            position.x += -direction.x;
            position.z += -direction.z;
        }

        if (leftJoy.h <= 100) {

            position.x += direction.z;
            position.z += -direction.x;

        }
        else if (leftJoy.h >= 200) {

            position.x += -direction.z;
            position.z += direction.x;
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
