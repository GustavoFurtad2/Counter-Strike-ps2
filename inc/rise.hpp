#pragma once

#include <tyra>

namespace Rise {

  class RiseGame:
  
    public Tyra::Game {

      public:
        
        RiseGame(Tyra::Engine* engine);
        ~RiseGame();

        void init();
        void loop();

      private:

        void loadSprite(Tyra::Sprite* sprite, const char filename[], float x, float y, float w, float h);

        Tyra::Engine* engine;
        Tyra::Sprite title;
        Tyra::Sprite background;
        Tyra::Sprite newgame;
    };

}