#include "cs.hpp"

#include <tyra>

namespace Cs {

    using namespace Tyra;

    CsGame::CsGame(Engine* t_engine) : engine(t_engine) {

    }

    CsGame::~CsGame() {
    }

    void CsGame::init() {

        engine->renderer.setClearScreenColor(Color(155.0f, 200.0f, 255.0f));
    }

    void CsGame::loop() {

        auto& renderer = engine->renderer;

        renderer.beginFrame();

        renderer.endFrame();
    }
}