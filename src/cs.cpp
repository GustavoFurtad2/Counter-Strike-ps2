#include "cs.hpp"
#include "gamestate.hpp"

#include <tyra>

namespace Cs {

    using namespace Tyra;

    GameState currentState = GameState::MainMenu;

    CsGame::CsGame(Engine* t_engine) : engine(t_engine), menu(engine), gameplay(engine) {

    }

    CsGame::~CsGame() {
    }

    void CsGame::init() {

        engine->renderer.setClearScreenColor(Color(155.0f, 200.0f, 255.0f));

        setGameState(GameState::MainMenu);
    }

    void CsGame::loop() {

        switch (currentState) {

            case GameState::MainMenu:

                menu.loop();
                menu.controls();
                break;

            case GameState::GamePlay:

                gameplay.loop();
                gameplay.controls();
                break;

        }

    }

    void CsGame::setGameState(GameState state) {

        currentState = state;

        switch (currentState) {

            case GameState::MainMenu:

                menu.init();
                break;

            case GameState::GamePlay:

                gameplay.init();
                break;
            
        }
    }

}