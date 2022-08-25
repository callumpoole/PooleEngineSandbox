#include "sandbox.h"

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

Poole::Rendering::Image textureHandle;
Poole::Rendering::Image textureHandle2;
Poole::Rendering::Image textureHandle3;
Poole::Rendering::Image* textureHandle3GreyScaleRGBA;
std::shared_ptr<Poole::Rendering::Image> spriteSheet;
std::shared_ptr<Poole::Rendering::SubImage> sub1;
std::shared_ptr<Poole::Rendering::SubImage> sub2;
std::shared_ptr<Poole::Rendering::SubImage> sub3;

std::shared_ptr<Poole::Rendering::TextRenderer> testText1;
Poole::Rendering::Image* fontSheet;

void Sandbox::BeginApp()
{
    using namespace Poole::Rendering;

#define IMAGE_PATH "../../sandbox/images/"

    //I know abs paths are not ideal for github, this is temp! And it's in a sandbox project anyways!
    textureHandle = Image(IMAGE_PATH "testTexture.png"); //RGB only!
    //textureHandle2 = Poole::Rendering::Image("D:/Callum/Desktop/testTextureRGBA.png");
    textureHandle2 = Image(IMAGE_PATH "ColorSquare16.png");

    textureHandle3 = Image(IMAGE_PATH "Gary_Redford_95_MJN.jpg");

    textureHandle3GreyScaleRGBA = ImageUtils::ToGreyscaleRGBA(&textureHandle3);
    
    spriteSheet.reset(new Image(IMAGE_PATH "spriteSheet.png"));
#undef IMAGE_PATH
 
    Poole::Rendering::SvgFontRenderer* s = new Poole::Rendering::SvgFontRenderer("asd");
  

  

  

    //Image GreyscaleFont = Image((u8*)SVG::GetBytes(), 512, 512, 1, true, true);
    ////GreyscaleFont = Image((u8*)GreyscaleFont.YFlipBytes().data(), 512, 512, 1, true, true);
    //
    //fontSheet = ImageUtils::GreyscaleToRGBA(ImageUtils::YFlip(&GreyscaleFont));

    //sub1.reset(new SubImage(spriteSheet, { 8,1}, {16,16}));
    sub1 = s->Convert('A', 70);
    sub2.reset(new SubImage(spriteSheet, { 9,1}, {16,16}));
    sub3.reset(new SubImage(spriteSheet, {10,1}, {16,16}));

    testText1 = TextRendererFactory::MakeRenderText();
    testText1->SetSize(0.1f);
    testText1->SetTextView(
        "Callum\n"
        "Can\n"
        "Now\n"
        "Do\n"
        "Mutli-line!"
    );
    testText1->SetColor(Colors::Red<fcolor4>);
    
}

void Sandbox::UpdateApp(float /*deltaTime*/)
{
    using namespace Poole::Rendering;
    using namespace Poole;

    const fvec2 mouseNorm = Input::GetMousePositionFloat(true, ECursorClamping::Clamp, ECursorNormalization::ZeroToOne);
    //LOG("Mouse = {} , {}", mouseNorm.x, mouseNorm.y);

    testText1->SetRotationRadians(3.1415926535 * mouseNorm.x * 2);
    testText1->SetShadowOffset(fvec2{ 0.05f, -0.05f } * 10.f * mouseNorm.y);

    constexpr i32 gridSize = 10;
    constexpr i32 halfGridSize = gridSize/2;
    for (i32 y = -halfGridSize; y < halfGridSize; y++)
    {
        for (i32 x = -halfGridSize; x < halfGridSize; x++)
        {
            if ((x + y) % 2 == 0)
            {
                Renderer2D::DrawTexturedQuad({ x / 10.f, y / 10.f }, { 0.1f, 0.1f }, textureHandle2);
            }
            else
            {
                Renderer2D::DrawQuad({ x/10.f, y/10.f }, { 0.1f, 0.1f }, fcolor4(0, (y + halfGridSize) / (float)gridSize, (x + halfGridSize) / (float)gridSize,1));
            }
        }
    }

    Renderer2D::DrawQuad({ 1.0, 0.f }, { 0.3f, 0.5f }, Colors::Green<fcolor4>);
    Renderer2D::DrawQuad({ 0.4, 0.8f }, { 0.25f, 0.2f }, Colors::Yellow<fcolor4>);
    Renderer2D::DrawQuad({ 0.0, -0.7f }, { 0.1f, 0.1f }, Colors::Cyan<fcolor4>);
    Renderer2D::DrawQuad({ 0.5f, -0.7f }, { 0.2f, 0.1f }, Colors::Purple<fcolor4>);
    
    Renderer2D::DrawTexturedQuad({ 0.0, 0.f }, { 0.5f, 0.5f }, textureHandle);
    Renderer2D::DrawTexturedQuad({ 0.9f, 0.7f }, { 0.25f, 0.25f }, textureHandle2);
    Renderer2D::DrawTexturedQuad({ -0.9f, -0.7f }, { 0.25f, 0.25f }, textureHandle3);
    Renderer2D::DrawTexturedQuad({ -0.9f, -0.1f }, { 0.25f, 0.25f }, *textureHandle3GreyScaleRGBA);
    Renderer2D::DrawTexturedQuad({ 0.8f, -0.7f }, { 0.2f, 0.2f }, *spriteSheet);
    
    Renderer2D::DrawSubTexturedQuad({ -0.75f, 0.75f }, { 0.25f, 0.25f }, *sub1);
    Renderer2D::DrawSubTexturedQuad({ -0.75f, 0.50f }, { 0.25f, 0.25f }, *sub2);
    Renderer2D::DrawSubTexturedQuad({ -1.00f, 0.50f }, { 0.25f, 0.25f }, *sub3);
    
    Renderer2D::DrawCircle({ -1.f, 0.0f }, {  0.5f, 1.0f }, Colors::Red<fcolor4>, 0, fvec2(0.f), mouseNorm.x, mouseNorm.y);
    Renderer2D::DrawCircle({  0.f, 0.8f }, { 0.05f, 0.2f }, Colors::Blue<fcolor4>, 0, fvec2(0.f), mouseNorm.x, mouseNorm.y);

    //Renderer2D::DrawSubTexturedQuad({ -1.00f, 0.75f }, { 0.25f, 0.25f }, *RenderTextFactory::DefaultFont->Convert('C'));

    
}

void Sandbox::EndApp()
{

}
