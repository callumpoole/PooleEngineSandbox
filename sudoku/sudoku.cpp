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

constexpr i32 gridSize = 9;
constexpr i32 gridElements = gridSize * gridSize;
constexpr f32 scale = 2;
constexpr f32 fitInSpaceOf = 10;
constexpr f32 recenterOffset = -scale / 2;
constexpr f32 nths = fitInSpaceOf / (float)gridSize;
constexpr fvec2 cellSize = fvec2{ scale, scale } / fitInSpaceOf;

std::array<std::shared_ptr<Poole::Rendering::TextRenderer>, gridElements> texts;

void Sudoku::BeginApp()
{
    using namespace Poole::Rendering;

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
}

void Sudoku::EndApp()
{

}
