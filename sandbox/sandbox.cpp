#include "sandbox.h"

#include "poole/core.h"

#include "poole/rendering/renderer.h"
#include "poole/rendering/renderer2D.h"
#include "poole/input/input.h"

#include "poole/rendering/image/image.h"
#include "poole/rendering/image/image_utils.h"
#include "poole/rendering/image/sub_image.h"
#include "poole/rendering/text/text_renderer.h"
#include "poole/rendering/text/text_renderer_factory.h"

//Proj
#include "renderer_testing.h"
#include "font_testing.h"
#include "collider_testing.h"

void Sandbox::BeginApp()
{
    //RendererTesting::Init();
    //FontTesting::Init();
    ColliderTesting::Init();
}

void Sandbox::UpdateApp(float deltaTime)
{
    //RendererTesting::Tick(deltaTime);
    //FontTesting::Tick(deltaTime);
    ColliderTesting::Tick(deltaTime);
}

void Sandbox::EndApp()
{
}
