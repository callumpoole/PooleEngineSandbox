#include "sandbox.h"

#include <iostream>
#include <filesystem>
#include "poole/rendering/renderer.h"
#include "poole/rendering/renderer2D.h"
#include "poole/rendering/batched_renderer2D.h"
#include "poole/rendering/rendering_primitives.h"
#include "poole/input/input.h"

#include "poole/rendering/image/image.h"
#include "poole/rendering/image/sub_image.h"

static constexpr bool TempRenderSeperately = true;

void TestMeshNoIndiciesSolidColor()
{
    using namespace Poole::Rendering;

    if constexpr (TempRenderSeperately)
    {
        StaticMeshNoIndiciesSolidColor4_2DTransform meshNoInd1;
        meshNoInd1.m_verts = std::vector<fvec3>{
            {-0.5f,  -0.5f,  0.0f}, { 0.5f,  -0.5f,  0.0f}, { 0.0f,   0.5f,  0.0f},
        };
        meshNoInd1.m_color = Colors::Green<fcolor4>;
        Renderer::Submit(std::move(meshNoInd1));


        StaticMeshNoIndiciesSolidColor4_2DTransform meshNoInd2;
        meshNoInd2.m_verts = std::vector<fvec3>{
            {-0.75f, -0.75f, 0.0f}, {-0.25f, -0.75f, 0.0f}, {-0.5f,  -0.5f,  0.0f},
        };
        meshNoInd2.m_color = Colors::Pink<fcolor4>;
        Renderer::Submit(std::move(meshNoInd2));


        StaticMeshNoIndiciesSolidColor4_2DTransform meshNoInd3;
        meshNoInd3.m_verts = std::vector<fvec3>{
            {0.75f, 0.75f, 0.0f}, {0.25f, 0.75f, 0.0f}, {0.5f,  0.5f,  0.0f},
        };
        meshNoInd3.m_color = Colors::Cyan<fcolor4>;
        Renderer::Submit(std::move(meshNoInd3));
    }
    else
    {
        StaticMeshNoIndiciesSolidColor4_2DTransform meshNoInd;
        meshNoInd.m_verts = std::vector<fvec3>{
            {-0.5f,  -0.5f,  0.0f}, { 0.5f,  -0.5f,  0.0f}, { 0.0f,  0.5f, 0.0f},
            {-0.75f, -0.75f, 0.0f}, {-0.25f, -0.75f, 0.0f}, {-0.5f, -0.5f, 0.0f},
            { 0.75f,  0.75f, 0.0f}, { 0.25f,  0.75f, 0.0f}, { 0.5f,  0.5f, 0.0f},
        };
        meshNoInd.m_color = Colors::Green<fcolor4>;
        Renderer::Submit(std::move(meshNoInd));
    }
}
void TestMeshSolidColor()
{
    using namespace Poole::Rendering;

    if constexpr (TempRenderSeperately)
    {
        StaticMeshSolidColor4_2DTransform mesh1;
        mesh1.m_verts = std::vector<fvec3>{
            {0.9f,   0.3f, 0.0f}, // top right
            {0.9f,  -0.3f, 0.0f}, // bottom right
            {0.6f,  -0.3f, 0.0f}, // bottom left
            {0.6f,   0.3f, 0.0f}, // top left
        };
        mesh1.m_indices = {
            0, 1, 3, /*first triangle*/ 1, 2, 3, /*second triangle*/
        };
        mesh1.m_color = Colors::Red<fcolor4>;
        Renderer::Submit(std::move(mesh1));


        StaticMeshSolidColor4_2DTransform mesh2;
        mesh2.m_verts = std::vector<fvec3>{
            { 0.9f,  0.9f, 0.0f}, // top right
            { 0.9f,  0.7f, 0.0f}, // bottom right
            { 0.7f,  0.7f, 0.0f}, // bottom left
            { 0.7f,  0.9f, 0.0f}, // top left
        };
        mesh2.m_indices = {
            0, 1, 3, /*first triangle*/ 1, 2, 3, /*second triangle*/
        };
        mesh2.m_color = Colors::Orange<fcolor4>;
        Renderer::Submit(std::move(mesh2));
    }
    else
    {
        StaticMeshSolidColor4_2DTransform mesh;
        mesh.m_verts = std::vector<fvec3>{
            {0.9f,   0.3f, 0.0f}, // top right
            {0.9f,  -0.3f, 0.0f}, // bottom right
            {0.6f,  -0.3f, 0.0f}, // bottom left
            {0.6f,   0.3f, 0.0f}, // top left
        
            { 0.9f,  0.9f, 0.0f}, // top right
            { 0.9f,  0.7f, 0.0f}, // bottom right
            { 0.7f,  0.7f, 0.0f}, // bottom left
            { 0.7f,  0.9f, 0.0f}, // top left
        };
        mesh.m_indices = {
              0,   1,   3, /*first triangle*/   1,   2,   3, /*second triangle*/
            4+0, 4+1, 4+3, /*third triangle*/ 4+1, 4+2, 4+3, /*fourth triangle*/
        };
        mesh.m_color = Colors::Red<fcolor4>;
        Renderer::Submit(std::move(mesh));
    }
}
void TestMeshVertexColor()
{
    using namespace Poole::Rendering;

    if constexpr (TempRenderSeperately)
    {
        StaticMeshVertexColor4_2DTransform meshWithColor1;
        meshWithColor1.m_verts = std::vector<Vertex3Color4>{
            {fvec3{ 0.2f,   0.2f, 0.0f}, /*top right*/      Colors::Yellow<fcolor4>},
            {fvec3{ 0.2f,  -0.2f, 0.0f}, /*bottom right*/   Colors::Green<fcolor4>},
            {fvec3{-0.2f,  -0.2f, 0.0f}, /*bottom left*/    Colors::White<fcolor4>},
            {fvec3{-0.2f,   0.2f, 0.0f}, /*top left*/       Colors::Purple<fcolor4>},
        };
        meshWithColor1.m_indices = {
            0, 1, 3, /*first triangle*/ 1, 2, 3, /*second triangle*/
        };
        meshWithColor1.m_position = { -0.7f, 0.2f };
        Renderer::Submit(std::move(meshWithColor1));


        StaticMeshVertexColor4_2DTransform meshWithColor2;
        meshWithColor2.m_verts = std::vector<Vertex3Color4>{
            {fvec3{-0.7f,  0.9f, 0.0f}, /*top right*/      Colors::Orange<fcolor4>},
            {fvec3{-0.7f,  0.7f, 0.0f}, /*bottom right*/   Colors::Cyan<fcolor4>},
            {fvec3{-0.9f,  0.7f, 0.0f}, /*bottom left*/    Colors::Grey<fcolor4>},
            {fvec3{-0.9f,  0.9f, 0.0f}, /*top left*/       Colors::Pink<fcolor4>},
        };
        meshWithColor2.m_indices = {
            0, 1, 3, /*first triangle*/ 1, 2, 3, /*second triangle*/
        };
        Renderer::Submit(std::move(meshWithColor2));
    }
    else
    {
        StaticMeshVertexColor4_2DTransform meshWithColor;
        meshWithColor.m_verts = std::vector<Vertex3Color4>{
            {fvec3{ 0.2f,   0.2f, 0.0f}, /*top right*/      Colors::Yellow<fcolor4>},
            {fvec3{ 0.2f,  -0.2f, 0.0f}, /*bottom right*/   Colors::Green<fcolor4>},
            {fvec3{-0.2f,  -0.2f, 0.0f}, /*bottom left*/    Colors::White<fcolor4>},
            {fvec3{-0.2f,   0.2f, 0.0f}, /*top left*/       Colors::Purple<fcolor4>},
        
            {fvec3{-0.7f,  0.9f, 0.0f}, /*top right*/      Colors::Orange<fcolor4>},
            {fvec3{-0.7f,  0.7f, 0.0f}, /*bottom right*/   Colors::Cyan<fcolor4>},
            {fvec3{-0.9f,  0.7f, 0.0f}, /*bottom left*/    Colors::Grey<fcolor4>}, 
            {fvec3{-0.9f,  0.9f, 0.0f}, /*top left*/       Colors::Pink<fcolor4>},
        };
        meshWithColor.m_indices = {
              0,   1,   3, /*first triangle*/   1,   2,   3, /*second triangle*/
            4+0, 4+1, 4+3, /*third triangle*/ 4+1, 4+2, 4+3, /*fourth triangle*/
        };
        Renderer::Submit(std::move(meshWithColor));
    }
}

void TempMoveTriangles()
{
    using namespace Poole::Rendering;

    StaticMeshNoIndiciesSolidColor4_2DTransform* Mesh =
        Renderer::GetMesh<StaticMeshNoIndiciesSolidColor4_2DTransform>(0);

    static float P = 0.f;
    P += 0.1f;

    using namespace Poole;
    const auto cursor = Input::GetMousePositionFloat(true, ECursorClamping::None, ECursorNormalization::CameraNegativeOneToOneAspect);

    LOG("Cursor Position at ({},{})", cursor.x, cursor.y);
    
    Mesh->m_position = { cursor.x, cursor.y };
    Mesh->m_scale = fvec2(0.05f);
    Mesh->m_rotation = P;
}

Poole::Rendering::Image textureHandle;
Poole::Rendering::Image textureHandle2;
Poole::Rendering::Image textureHandle3;
std::shared_ptr<Poole::Rendering::Image> spriteSheet;
std::shared_ptr<Poole::Rendering::SubImage> sub1;
std::shared_ptr<Poole::Rendering::SubImage> sub2;
std::shared_ptr<Poole::Rendering::SubImage> sub3;

void Sandbox::BeginApp()
{
#define IMAGE_PATH "../../sandbox/images/"

    //I know abs paths are not ideal for github, this is temp! And it's in a sandbox project anyways!
    textureHandle = Poole::Rendering::Image(IMAGE_PATH "testTexture.png"); //RGB only!
    //textureHandle2 = Poole::Rendering::Image("D:/Callum/Desktop/testTextureRGBA.png");
    textureHandle2 = Poole::Rendering::Image(IMAGE_PATH "ColorSquare16.png");

    textureHandle3 = Poole::Rendering::Image(IMAGE_PATH "Gary_Redford_95_MJN.jpg");
    
    spriteSheet.reset(new Poole::Rendering::Image(IMAGE_PATH "spriteSheet.png"));
 
#undef IMAGE_PATH

    sub1.reset(Poole::Rendering::SubImage::Create(spriteSheet, { 8,8}, {16,16}));
    sub2.reset(Poole::Rendering::SubImage::Create(spriteSheet, { 9,8}, {16,16}));
    sub3.reset(Poole::Rendering::SubImage::Create(spriteSheet, {10,8}, {16,16}));
    

    //TestMeshNoIndiciesSolidColor();
    //TestMeshSolidColor();
    //TestMeshVertexColor();
}

void Sandbox::UpdateApp(float /*deltaTime*/)
{
    //TempMoveTriangles();

    using namespace Poole::Rendering;
    using namespace Poole;

    const fvec2 mouseNorm = Input::GetMousePositionFloat(true, ECursorClamping::Clamp, ECursorNormalization::ZeroToOne);
    //LOG("Mouse = {} , {}", mouseNorm.x, mouseNorm.y);

//  Renderer2D::DrawQuad({ 1.0, 0.f }, { 0.3f, 0.5f }, Colors::Green<fcolor4>, 0.f, fvec2(0.f));
//  Renderer2D::DrawQuad({ 0.4, 0.8f }, { 0.25f, 0.2f }, Colors::Yellow<fcolor4>, 0.f, fvec2(0.f));
//  Renderer2D::DrawQuad({ 0.0, -0.7f }, { 0.1f, 0.1f }, Colors::Cyan<fcolor4>, 0.f, fvec2(0.f));
//  Renderer2D::DrawQuad({ 0.5f, -0.7f }, { 0.2f, 0.1f }, Colors::Purple<fcolor4>, 0.f, fvec2(0.f));
//
//  Renderer2D::DrawTexturedQuad({ 0.0, 0.f }, { 0.5f, 0.5f }, textureHandle);
//  Renderer2D::DrawTexturedQuad({ 0.9f, 0.7f }, { 0.25f, 0.25f }, textureHandle2);
//  Renderer2D::DrawTexturedQuad({ -0.9f, -0.7f }, { 0.25f, 0.25f }, textureHandle3);
//  Renderer2D::DrawTexturedQuad({ 0.8f, -0.7f }, { 0.2f, 0.2f }, *spriteSheet);
//
//  Renderer2D::DrawCircle({ -1.0, 0.f }, { 0.5f, 1.f }, Colors::Red<fcolor4>, 0.f, fvec2(0.f), mouseNorm.x, mouseNorm.y);
//  Renderer2D::DrawCircle({ 0, 0.8f }, { 0.05f, 0.2f }, Colors::Blue<fcolor4>, 0.f, fvec2(0.f), mouseNorm.x, mouseNorm.y);

//  Renderer2D::DrawSubTexturedQuad({ -0.75f, 0.75f }, { 0.125f, 0.125f }, *sub1);
//  Renderer2D::DrawSubTexturedQuad({ -0.75f, 0.50f }, { 0.125f, 0.125f }, *sub2);
//  Renderer2D::DrawSubTexturedQuad({ -1.00f, 0.50f }, { 0.125f, 0.125f }, *sub3);





    BatchedRenderer2D::DrawQuad({ 1.0, 0.f }, { 0.3f, 0.5f }, Colors::Green<fcolor4>);
    BatchedRenderer2D::DrawQuad({ 0.4, 0.8f }, { 0.25f, 0.2f }, Colors::Yellow<fcolor4>);
    BatchedRenderer2D::DrawQuad({ 0.0, -0.7f }, { 0.1f, 0.1f }, Colors::Cyan<fcolor4>);
    BatchedRenderer2D::DrawQuad({ 0.5f, -0.7f }, { 0.2f, 0.1f }, Colors::Purple<fcolor4>);

    BatchedRenderer2D::DrawTexturedQuad({ 0.0, 0.f }, { 0.5f, 0.5f }, textureHandle);
    BatchedRenderer2D::DrawTexturedQuad({ 0.9f, 0.7f }, { 0.25f, 0.25f }, textureHandle2);
    BatchedRenderer2D::DrawTexturedQuad({ -0.9f, -0.7f }, { 0.25f, 0.25f }, textureHandle3);
    BatchedRenderer2D::DrawTexturedQuad({ 0.8f, -0.7f }, { 0.2f, 0.2f }, *spriteSheet);

    BatchedRenderer2D::DrawSubTexturedQuad(ftransform2D{ { -1.f, 0 }, { 1.f, 1.0f }, 0 }, *sub1);
    BatchedRenderer2D::DrawSubTexturedQuad(ftransform2D{ {  0.f, 0 }, { 1.f, 1.0f }, 0 }, *sub2);
    BatchedRenderer2D::DrawSubTexturedQuad(ftransform2D{ {  1.f, 0 }, { 1.f, 1.0f }, 0 }, *sub3);
}

void Sandbox::EndApp()
{

}
