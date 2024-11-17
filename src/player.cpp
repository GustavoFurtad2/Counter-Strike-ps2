#include "player.hpp"

namespace Tyra {

    Player::Player(Tyra::Engine* t_engine) : engine(t_engine) {

    }

    Player::~Player() {

        engine->renderer.getTextureRepository().freeBySprite(healthSymbol);

    }

    void Player::init() {

        loadSprite(&healthSymbol, "player/healthSymbol.png", 5.0f, 411.0f, 32.0f, 32.0f);
    }

    void Player::update() {

        engine->renderer.renderer2D.render(healthSymbol);
    }

    void Player::loadSprite(Tyra::Sprite* sprite, const char filename[], float x, float y, float w, float h) {

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