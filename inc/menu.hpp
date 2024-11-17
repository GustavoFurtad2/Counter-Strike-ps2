#pragma once

#include <tyra>

namespace Tyra {

    class Menu {

        public:

            Menu(Tyra::Engine* engine);
            ~Menu();

            void init();
            void loop();
            void controls();
            
        private:

            Tyra::Engine* engine;

            Tyra::Sprite logo;
            Tyra::Sprite loading;
            Tyra::Sprite background;

            void loadSprite(Tyra::Sprite* sprite, const char filename[], float x, float y, float w, float h);

    };
}