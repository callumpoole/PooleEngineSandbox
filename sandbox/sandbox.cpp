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

#include "poole/physics/collision_2D/box_collider_2D.h"
#include "poole/physics/collision_2D/circle_collider_2D.h"
#include "poole/physics/collision_2D/collision_manager_2D.h"

std::shared_ptr<Poole::BoxCollider2D> box1;
std::shared_ptr<Poole::BoxCollider2D> box2;
std::shared_ptr<Poole::CircleCollider2D> circle1;
std::shared_ptr<Poole::CircleCollider2D> circle2;

void Sandbox::BeginApp()
{
    //RendererTesting::Init();
    //FontTesting::Init();

    box1 = Poole::ColliderManager2D::MakeCollider<Poole::BoxCollider2D>(fvec2{  0.4, 0.4 }, fvec2{ 0.4, 0.4 }, PI / 3);
    box2 = Poole::ColliderManager2D::MakeCollider<Poole::BoxCollider2D>(fvec2{ -0.4, 0.8 }, fvec2{ 0.1, 0.35 }, PI / 8);

    circle1 = Poole::ColliderManager2D::MakeCollider<Poole::CircleCollider2D>(fvec2{ -0.2, -0.5 }, 0.1f);
    circle2 = Poole::ColliderManager2D::MakeCollider<Poole::CircleCollider2D>(fvec2{ -0.9, 0.8 }, 0.1f);
}

float aa = 0.0f;
float bb = 1.2f;

void Sandbox::UpdateApp(float deltaTime)
{
    //RendererTesting::Tick(deltaTime);
    //FontTesting::Tick(deltaTime);

    using namespace Poole;

    const fvec2 mouseToScene = Input::GetMousePositionToScene();

    box1->DebugDraw();
    box2->DebugDraw();


    static_cast<BoxCollider2D*>(box2.get())->SetPosition(mouseToScene);

    aa += deltaTime / 10.f;
    bb += deltaTime / 20.f;

    static_cast<BoxCollider2D*>(box1.get())->SetRadians(aa);
    static_cast<BoxCollider2D*>(box2.get())->SetRadians(bb);


    circle1->DebugDraw();
    circle2->DebugDraw();
    static_cast<CircleCollider2D*>(circle2.get())->SetPosition(mouseToScene + fvec2{0.5,0.5});
}

void Sandbox::EndApp()
{

}
