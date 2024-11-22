#pragma once

#include <tyra>

#define FONT_CHAR_SIZE 96

namespace Tyra {

    class Font {

        public:

            Font();
            ~Font();

            void load(TextureRepository& repository, Renderer2D* renderer);
            void free(TextureRepository& repository);

            void print(const std::string& text, const int& x, const int& y, Color color);

        private:

            Tyra::Renderer2D* renderer2D;

            Tyra::Sprite fontMap;

            std::array<Tyra::Sprite, FONT_CHAR_SIZE> font;

            const static int chars[FONT_CHAR_SIZE];
            const static int charWidths[FONT_CHAR_SIZE];

    };
}