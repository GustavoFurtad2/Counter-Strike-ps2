#include <tyra>

#include "gameplay.hpp"
#include "gamestate.hpp"

namespace Tyra {

    Gameplay::Gameplay(Tyra::Engine* t_engine) : engine(t_engine), camera(&t_engine->pad), player(t_engine) {

    }

    Gameplay::~Gameplay() {

        engine->renderer.getTextureRepository().freeByMesh(mesh.get());
    }

    void Gameplay::init() {

        player.init();

        stapip.setRenderer(&engine->renderer.core);

        loadMesh();

    }

    void Gameplay::loop() {

        if (!initied) {

            init();
            initied = true;
        }
        
        camera.update();

        auto& renderer = engine->renderer;

        renderer.beginFrame(camera.getCameraInfo());

        renderer.renderer3D.usePipeline(stapip);

        stapip.render(mesh.get(), renderOptions);

        player.update();

        renderer.endFrame();
    }

    void Gameplay::controls() {

        if (engine->pad.getPressed().Square) {

            Cs::currentState = Cs::GameState::MainMenu;
        }
    }

    void Gameplay::loadMesh() {

        ObjLoaderOptions options;
        options.scale = 200.0f;

        auto data = ObjLoader::load(FileUtils::fromCwd("de_dust2/de_dust2.obj"), options);

        mesh = std::make_unique<StaticMesh>(data.get());

        renderOptions.frustumCulling = Tyra::PipelineFrustumCulling_None;

        engine->renderer.getTextureRepository().addByMesh(mesh.get(), FileUtils::fromCwd("de_dust2/"), "png");
    }

    void Gameplay::loadSprite(Tyra::Sprite* sprite, const char filename[], float x, float y, float w, float h) {

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