#include "font.hpp"

namespace Tyra {

    const int Font::chars[26] {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
        'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
    
    Font::Font() {

    }

    Font::~Font() {

    }

    void Font::load(TextureRepository& repository, Renderer2D* renderer) {

        renderer2D = renderer;

        auto filepath = FileUtils::fromCwd("menu/tahoma_font_map.png");
        auto* texture = repository.add(filepath);

        texture->addLink(tahomaFontMap.id);

        unsigned int collumn = 0;
        unsigned int row = 0;

        float characterWidth = 28.0f;
        float characterHeight = 28.0f;

        for (int i = 0; i < 26; i++) {

            font[i].id = tahomaFontMap.id;
            font[i].size = Vec2(characterWidth, 50.0f);
            font[i].offset = Vec2(85 + (32 * (collumn + 1) ), (row == 0 ? -24 : 6) + (row == 1 ? -14 : 0) + ( characterHeight * (row + 1) ) );

            collumn++;

            if (collumn == 9) {

                collumn = 0;
                row++;
            }
        }
    }

    void Font::free(TextureRepository& repository) {

        repository.freeBySprite(tahomaFontMap);

        for (unsigned int i = 0; i < 26; i++) {
            repository.freeBySprite(font[i]);
        }
    }

    void Font::drawText(const std::string& text, const int& x, const int& y, Color color) {

        unsigned int sizeText = text.size();

        unsigned int offsetX = 0;
        unsigned int offsetY = 0;

        for (unsigned int i = 0; i < sizeText; i++) {

            unsigned int position = text[i];

            Tyra::Sprite fontSprite = font[0];

            for (unsigned int j = 0; j < 26; j++) {

                if (position == chars[j]) {

                    position = j;
                    fontSprite = font[j];
                    fontSprite.color = color;
                    fontSprite.position = Vec2(x + offsetX, y + offsetY);

                    break;
                }
            }

            if (position == '\n') {

                offsetY += 32.0f;
                offsetX = 0.0f;
            }
            else {

                if ( (position != ' ') && (position != '\t') ) {

                    renderer2D->render(fontSprite);
                    offsetX += 32.0f;
                }
                else {
                    offsetX += 2;
                }
            }
        }
    }
}