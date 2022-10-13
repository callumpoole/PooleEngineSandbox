#include "font_testing.h"

#include "poole/core.h"


#include "poole/rendering/renderer.h"
#include "poole/rendering/renderer2D.h"
#include "poole/input/input.h"

#include "poole/rendering/image/image.h"
#include "poole/rendering/image/image_utils.h"
#include "poole/rendering/image/sub_image.h"
#include "poole/rendering/text/text_renderer.h"
#include "poole/rendering/text/text_renderer_factory.h"

namespace FontTesting
{
    std::shared_ptr<Poole::Rendering::TextRenderer> testText1;
    std::shared_ptr<Poole::Rendering::TextRenderer> testText2;
    std::shared_ptr<Poole::Rendering::TextRenderer> testText3;

    void Init()
	{
        using namespace Poole::Rendering;


        testText1 = TextRendererFactory::MakeRenderText(false);
        testText1->SetPosition({ -0.48, 0.48, 0 });
        testText1->SetScale(0.30f);
        testText1->SetTextView("XXXXX\nXXXXX\nXXXXX");
        /*testText1->SetTextView(
            "\n"
            "\n"
            "\n"
            "\n"
            "555OOOOOOOOOOXOOOOOOOOOO555\n"
            "\n"
            "\n"
            "\n"
            ""
        );*/
        testText1->SetColor(Colors::Red<fcolor4> *Colors::Alpha50<fcolor4>);
        testText1->SetHorizontalPivot(EHorizontal::Center);
        testText1->SetVerticalPivot(EVertical::Middle);

        testText2 = TextRendererFactory::MakeRenderText(false);
        testText2->SetPosition({ -0.5, 0.5, 0 });
        testText2->SetScale(0.30f);


        //testText2->SetTextView("XXXXX\nXXXXX\nXXXXX");
        testText2->SetTextView("XXXXX");

        //testText2->SetTextView(
        //    "111OOOOOOOOOOXOOOOOOOOOO111\n"
        //    "222OOOOOOOOOOXOOOOOOOOOO222\n"
        //    "333OOOOOOOOOOXOOOOOOOOOO333\n"
        //    "444OOOOOOOOOOXOOOOOOOOOO444\n"
        //    "555OOOOOOOOOOXOOOOOOOOOO555\n"
        //    "666OOOOOOOOOOXOOOOOOOOOO666\n"
        //    "777OOOOOOOOOOXOOOOOOOOOO777\n"
        //    "888OOOOOOOOOOXOOOOOOOOOO888\n"
        //    "999OOOOOOOOOOXOOOOOOOOOO999"
        //);

        testText2->SetColor(Colors::Blue<fcolor4> *Colors::Alpha50<fcolor4>);
        testText2->SetHorizontalPivot(EHorizontal::Left);
        testText2->SetVerticalPivot(EVertical::Top);


        testText3 = TextRendererFactory::MakeRenderText(false);
        testText3->SetPosition({ -0.52, 0.52, 0 });
        testText3->SetScale(0.30f);
        testText3->SetTextView("XXXXX\nXXXXX\nXXXXX");
        //testText3->SetTextView("XXXXX");

        testText3->SetColor(Colors::Green<fcolor4> *Colors::Alpha50<fcolor4>);
        testText3->SetHorizontalPivot(EHorizontal::Right);
        testText3->SetVerticalPivot(EVertical::Bottom);
	}
    void Tick(float /*deltaTime*/)
	{
        using namespace Poole::Rendering;
        using namespace Poole;

        const fvec2 mouseNorm = Input::GetMousePositionFloat(true, ECursorClamping::Clamp, ECursorNormalization::ZeroToOne);
        //LOG("Mouse = {} , {}", mouseNorm.x, mouseNorm.y);

        testText1->SetRotationRadians(3.1415926535f * mouseNorm.x * 2.f);
        testText1->SetShadowOffset(fvec2{ 0.05f, -0.05f } *10.f * mouseNorm.y);

        testText2->SetRotationRadians(3.1415926535f * mouseNorm.x * 2.f);
        testText2->SetShadowOffset(fvec2{ 0.05f, -0.05f } *10.f * mouseNorm.y);

        testText3->SetRotationRadians(3.1415926535f * mouseNorm.x * 2.f);
        testText3->SetShadowOffset(fvec2{ 0.05f, -0.05f } *10.f * mouseNorm.y);
	}
}
