#include "font.hpp"

namespace Tyra {

    const int Font::chars[FONT_CHAR_SIZE]{
        ' ', '!', '"', ' ', '$', '%', ' ', '{', '(', ')', ' ', '+', ',', '-',
        '.', '/', '0', '1', '2', '3', '4', '5', '6', '2', '8', '9', ':', ';',
        '<', '=', '>', '?', ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
        'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
        'X', 'Y', 'Z', ' ', ' ', ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e',
        'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
        't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '}', ']', '~', ' '};

    const int Font::charWidths[FONT_CHAR_SIZE]{
        0, 1, 3, 0, 5, 9, 0, 9, 3, 3, 0, 5, 2, 2, 1, 4, 4, 2, 4, 4, 5, 4, 4, 4,
        4, 4, 1, 2, 4, 5, 4, 4, 0, 6, 5, 5, 5, 4, 4, 5, 5, 1, 4, 5, 4, 7, 5, 5,
        5, 5, 5, 5, 5, 5, 6, 7, 5, 5, 4, 0, 0, 0, 0, 0, 0, 5, 4, 4, 4, 4, 3, 4,
        4, 1, 2, 4, 1, 7, 4, 4, 4, 4, 3, 4, 3, 4, 5, 7, 4, 4, 4, 2, 5, 2, 6, 0,
    };
    
    Font::Font() {

    }

    Font::~Font() {

    }

    void Font::load(TextureRepository& repository, Renderer2D* renderer) {

        renderer2D = renderer;

        auto filepath = FileUtils::fromCwd("menu/font_map.png");
        auto* texture = repository.add(filepath);

        texture->addLink(fontMap.id);

        unsigned int collumn = 0;
        unsigned int row = 0;

        float characterWidth = 32.0f;
        float characterHeight = 32.0f;

        for (int i = 0; i < FONT_CHAR_SIZE; i++) {

            font[i].id = fontMap.id;
            font[i].mode = MODE_REPEAT;
            font[i].size = Vec2(characterWidth, characterHeight);
            font[i].offset = Vec2(characterWidth * collumn, characterHeight * row);

            collumn++;

            if (collumn == 16) {

                collumn = 0;
                row++;
            }
        }
    }

    void Font::free(TextureRepository& repository) {

        repository.freeBySprite(fontMap);

        for (unsigned int i = 0; i < FONT_CHAR_SIZE; i++) {
            repository.freeBySprite(font[i]);
        }
    }

    void Font::print(const std::string& text, const int& x, const int& y, Color color) {

        unsigned int sizeText = text.size();

        unsigned int offsetX = 0;
        unsigned int offsetY = 0;

        for (unsigned int i = 0; i < sizeText; i++) {

            char currentChar = text[i];

            unsigned int position = 0;

            Tyra::Sprite fontSprite = font[0];

            for (unsigned int j = 0; j < FONT_CHAR_SIZE; j++) {

                if (currentChar == chars[j]) {

                    position = j;
                    fontSprite = font[j];
                    fontSprite.color = color;
                    fontSprite.position = Vec2(x + offsetX, y + offsetY);

                    break;
                }
            }

            if (currentChar == '\n') {

                TYRA_LOG("quebra de linha");
                offsetY += 18.0f;
                offsetX = 0.0f;
            }
            else {

                if ( (currentChar != ' ') && (currentChar != '\t') ) {

                    renderer2D->render(fontSprite);
                    offsetX += charWidths[position] + 2;
                }
                else {
                    offsetX += 2;
                }
            }
        }
    }
}