#pragma once

#include <tyra>
#include <memory>

#include "./menu.hpp"
#include "./gameplay.hpp"
#include "./gamestate.hpp"

namespace Cs {

    class CsGame:
  
    	public Tyra::Game {

        	public:
        
        	    CsGame(Tyra::Engine* engine);
        	    ~CsGame();

        		void init();
        		void loop();

      		private:

        		Tyra::Engine* engine;

				Tyra::Menu menu;
				Tyra::Gameplay gameplay;

				void setGameState(GameState state);

    };

}