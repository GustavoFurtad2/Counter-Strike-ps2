#pragma once

#include <tyra>
#include <memory>

#include "./camera.hpp"

namespace Tyra {

    class Gameplay {

        public:

            Gameplay(Tyra::Engine* engine);
            ~Gameplay();

            void init();
            void loop();
            void controls();
            void loadMesh();
            
        private:

            Tyra::Engine* engine;

            Tyra::Camera camera;

            Tyra::StaticPipeline stapip;

			Tyra::StaPipOptions renderOptions;

			std::unique_ptr<Tyra::StaticMesh> mesh;

            bool initied = false;

            void loadSprite(Tyra::Sprite* sprite, const char filename[], float x, float y, float w, float h);
        
    };
}
