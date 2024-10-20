#include "menu.hpp"
#include "gamestate.hpp"

#include <tyra>

namespace Tyra {

    Menu::Menu(Tyra::Engine* t_engine) : engine(t_engine) {

    }

    Menu::~Menu() {

        engine->renderer.getTextureRepository().freeBySprite(loading);
        engine->renderer.getTextureRepository().freeBySprite(background);
    }

    void Menu::init() {

        loadSprite(&loading, "menu/loading.png", 0.0f, 0.0f, 512.0f, 448.0f);
        loadSprite(&background, "menu/background.png", 0.0f, 0.0f, 512.0f, 448.0f);
    }

    void Menu::loop() {
        
        auto& renderer = engine->renderer;

        renderer.beginFrame();

        renderer.renderer2D.render(background);
        
        renderer.endFrame();
        
    }

    void Menu::controls() {

        if (engine->pad.getPressed().Cross) {

            Cs::currentState = Cs::GameState::GamePlay;

            engine->renderer.beginFrame();

            engine->renderer.renderer2D.render(loading);
            
            engine->renderer.endFrame();

        }
    }

    void Menu::loadSprite(Tyra::Sprite* sprite, const char filename[], float x, float y, float w, float h) {

        const auto& screenSettings = engine->renderer.core.getSettings();

        sprite->mode = SpriteMode::MODE_STRETCH;
        sprite->size = Vec2(w, h);
        sprite->position = Vec2(x, y);

        auto& renderer = engine->renderer;
        auto& textureRepository = renderer.getTextureRepository();
        auto filepath = FileUtils::fromCwd(filename);

        auto* texture = textureRepository.add(filepath);
        texture->addLink(sprite->id);

    }
}
