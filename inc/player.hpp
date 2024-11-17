#pragma once

#include <tyra>

namespace Tyra {

    class Player {

        public:

            Player(Tyra::Engine* engine);
            ~Player();

            void init();
            void update();

            int health = 100;

        private:

            Tyra::Engine* engine;

            Tyra::Sprite healthSymbol;

            void loadSprite(Tyra::Sprite* sprite, const char filename[], float x, float y, float w, float h);

    };
}