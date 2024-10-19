#pragma once

#include <tyra>

namespace Tyra {

    class Camera {

        public:

            Camera(Pad* pad);
            ~Camera();

            Vec4 lookAt;
            Vec4 position;

            Vec4 unitCircle;

            CameraInfo3D getCameraInfo() {
                return CameraInfo3D(&position, &lookAt);
            }

            void update();

        private:

            void updatePosition();
            void updateLookAt();

            Pad* pad;

            float speed = 5.0f;

            float minSpeed = 0.1f;
            float maxSpeed = 15.0f;

            float acceleration = 0.25;

            float circleRotation, circleLength, lookAtHeight;
    };

}