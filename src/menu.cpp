#include "menu.hpp"
#include "gamestate.hpp"

#include <tyra>

namespace Tyra {

    Menu::Menu(Tyra::Engine* t_engine) : engine(t_engine) {

    }

    Menu::~Menu() {

        engine->renderer.getTextureRepository().freeBySprite(logo);
        engine->renderer.getTextureRepository().freeBySprite(loading);
        engine->renderer.getTextureRepository().freeBySprite(background);

        font.free(engine->renderer.getTextureRepository());
    }

    void Menu::init() {

        loadSprite(&logo, "menu/logo.png", 25.0f, 290.0f, 256.0f, 256.0f);
        loadSprite(&loading, "menu/loading.png", 0.0f, 0.0f, 512.0f, 448.0f);
        loadSprite(&background, "menu/background.png", 0.0f, 0.0f, 512.0f, 448.0f);

        font.load(engine->renderer.getTextureRepository(), &engine->renderer.renderer2D);
    }

    void Menu::loop() {
        
        auto& renderer = engine->renderer;

        renderer.beginFrame();

        renderer.renderer2D.render(background);

        renderer.renderer2D.render(logo);

        font.print("New game", 10, 250, Color(255, 255, 255));
        font.print("Find Servers", 10, 270, Color(255, 255, 255));
        font.print("Options", 10, 290, Color(255, 255, 255));
        font.print("Quit", 10, 310, Color(255, 255, 255));
        
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