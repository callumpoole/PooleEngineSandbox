#include "sudoku.h"

#include <iostream>
#include <filesystem>
#include "poole/rendering/renderer.h"
#include "poole/rendering/renderer2D.h"
#include "poole/input/input.h"

#include "poole/rendering/image/image.h"
#include "poole/rendering/image/image_utils.h"
#include "poole/rendering/image/sub_image.h"
#include "poole/rendering/text/svg_font_renderer.h"
#include "poole/rendering/text/text_renderer.h"
#include "poole/rendering/text/text_renderer_factory.h"

#include "poole/core/core_logging.h"
//
//Poole::Rendering::Image* textureHandle;
//Poole::Rendering::Image* textureHandle2;
//Poole::Rendering::Image* textureHandle3;
//
//Poole::Rendering::Image* oddWidth;
//Poole::Rendering::Image* oddHeight;
//
//Poole::Rendering::Image* textureHandle3GreyScaleRGBA;
//std::shared_ptr<Poole::Rendering::Image> spriteSheet;
//std::shared_ptr<Poole::Rendering::SubImage> sub1;
//std::shared_ptr<Poole::Rendering::SubImage> sub2;
//std::shared_ptr<Poole::Rendering::SubImage> sub3;
//
//Poole::Rendering::Image* fontSheet;

constexpr i32 gridSize = 19;
constexpr i32 gridElements = gridSize * gridSize;
constexpr f32 scale = 1;
constexpr f32 fitInSpaceOf = 20;
constexpr f32 recenterOffset = -scale / 2;
constexpr f32 nths = fitInSpaceOf / (float)gridSize;
constexpr fvec2 cellSize = fvec2{ scale, scale } / fitInSpaceOf;

std::array<std::shared_ptr<Poole::Rendering::TextRenderer>, gridElements> texts;

void Sudoku::BeginApp()
{
    using namespace Poole::Rendering;

//#define IMAGE_PATH "../../sudoku/images/"
//    textureHandle = new Image(IMAGE_PATH "testTexture.png"); //RGB only!
//    textureHandle2 = new Image(IMAGE_PATH "ColorSquare16.png");
//    textureHandle3 = new Image(IMAGE_PATH "Gary_Redford_95_MJN.jpg");
//
//    oddWidth = new Image(IMAGE_PATH "ColorSquare12OddWidth.png");
//    oddHeight = new Image(IMAGE_PATH "ColorSquare12OddHeight.png");
//
//    textureHandle3GreyScaleRGBA = ImageUtils::ToGreyscaleRGBA(textureHandle3);
//
//    spriteSheet.reset(new Image(IMAGE_PATH "spriteSheet.png"));
//#undef IMAGE_PATH
//
//    sub1.reset(new SubImage(spriteSheet, { 8,1}, {16,16}));
//    sub2.reset(new SubImage(spriteSheet, { 9,1}, {16,16}));
//    sub3.reset(new SubImage(spriteSheet, {10,1}, {16,16}));

    for (i32 y = 0; y < gridSize; y++)
    {
        for (i32 x = 0; x < gridSize; x++)
        {
            i32 i = x + y * gridSize;
            texts[i] = TextRendererFactory::MakeRenderText(false);
            texts[i]->SetPosition(fvec3{ 
                scale * x / (float)gridSize + recenterOffset + nths * cellSize.x / scale / 2,
                scale * y / (float)gridSize + recenterOffset + nths * cellSize.y / scale / 2, 0 });
            texts[i]->SetSize(cellSize.x);
            texts[i]->SetText(std::string(1, char(x + '1')));
            texts[i]->SetColor(Colors::Black<fcolor4>);
            texts[i]->SetShadowOffset(fvec2(0.025f, -0.025f));
            texts[i]->SetShadowColor(Colors::Grey<fvec4>);
        }
    }
}

void Sudoku::UpdateApp(float /*deltaTime*/)
{
    using namespace Poole::Rendering;
    using namespace Poole;

    for (i32 y = 0; y < gridSize; y++)
    {
        for (i32 x = 0; x < gridSize; x++)
        {
            const fcolor4 col = Colors::White<fcolor4>;
            Renderer2D::DrawQuad({ scale * x / (float)gridSize + recenterOffset + nths * cellSize.x / scale ,
                                   scale * y / (float)gridSize + recenterOffset + nths * cellSize.y / scale }, cellSize, col);
        }
    }

    //Renderer2D::DrawQuad({ 1.0, 0.f }, { 0.3f, 0.5f }, Colors::Green<fcolor4>);
    //Renderer2D::DrawQuad({ 0.4, 0.8f }, { 0.25f, 0.2f }, Colors::Yellow<fcolor4>);
    //Renderer2D::DrawQuad({ 0.0, -0.7f }, { 0.1f, 0.1f }, Colors::Cyan<fcolor4>);
    //Renderer2D::DrawQuad({ 0.5f, -0.7f }, { 0.2f, 0.1f }, Colors::Purple<fcolor4>);
    //
    //Renderer2D::DrawTexturedQuad({ 0.0, 0.f }, { 0.5f, 0.5f }, *textureHandle);
    //Renderer2D::DrawTexturedQuad({ 0.9f, 0.7f }, { 0.25f, 0.25f }, *textureHandle2);
    //Renderer2D::DrawTexturedQuad({ -0.9f, -0.7f }, { 0.25f, 0.25f }, *textureHandle3);
    //Renderer2D::DrawTexturedQuad({ -0.9f, -0.1f }, { 0.25f, 0.25f }, *textureHandle3GreyScaleRGBA);
    //Renderer2D::DrawTexturedQuad({ 0.8f, -0.7f }, { 0.2f, 0.2f }, *spriteSheet);
    //
    //Renderer2D::DrawSubTexturedQuad({ -0.75f, 0.75f }, { 0.25f, 0.25f }, *sub1);
    //Renderer2D::DrawSubTexturedQuad({ -0.75f, 0.50f }, { 0.25f, 0.25f }, *sub2);
    //Renderer2D::DrawSubTexturedQuad({ -1.00f, 0.50f }, { 0.25f, 0.25f }, *sub3);
    //
    //Renderer2D::DrawCircle({ -1.f, 0.0f }, {  0.5f, 1.0f }, Colors::Red<fcolor4>, 0, fvec2(0.f), mouseNorm.x, mouseNorm.y);
    //Renderer2D::DrawCircle({  0.f, 0.8f }, { 0.05f, 0.2f }, Colors::Blue<fcolor4>, 0, fvec2(0.f), mouseNorm.x, mouseNorm.y);
}

void Sudoku::EndApp()
{

}
