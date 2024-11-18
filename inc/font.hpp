#pragma once

#include <tyra>

namespace Tyra {

    class Font {

        public:

            Font();
            ~Font();

            void load(TextureRepository& repository, Renderer2D* renderer);
            void free(TextureRepository& repository);

            void drawText(const std::string& text, const int& x, const int& y, Color color);

        private:

            Tyra::Renderer2D* renderer2D;

            Tyra::Sprite tahomaFontMap;

            std::array<Tyra::Sprite, 82> font;

            const static int chars[26];

    };
}