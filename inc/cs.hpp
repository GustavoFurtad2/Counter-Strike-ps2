#pragma once

#include <tyra>
#include <memory>
#include "./camera.hpp"

namespace Cs {

    class CsGame:
  
    	public Tyra::Game {

        	public:
        
        		CsGame(Tyra::Engine* engine);
        		~CsGame();

        		void init();
        		void loop();

      		private:

    };

}
