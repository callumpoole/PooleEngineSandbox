#include "sandbox.h"

#include <iostream>
#include "poole/rendering/renderer.h"
#include "poole/rendering/rendering_primitives.h"


void TestMeshNoIndiciesSolidColor()
{
    Poole::Rendering::StaticMeshNoIndiciesSolidColor3_2DTransform meshNoInd;
    meshNoInd.m_verts = std::vector<Poole::Rendering::Vertex>{
        {-0.5f,  -0.5f,  0.0f},
        { 0.5f,  -0.5f,  0.0f},
        { 0.0f,   0.5f,  0.0f},

        //{-0.75f, -0.75f, 0.0f},
        //{-0.25f, -0.75f, 0.0f},
        //{-0.5f,  -0.5f,  0.0f},

        //{0.75f, 0.75f, 0.0f},
        //{0.25f, 0.75f, 0.0f},
        //{0.5f,  0.5f,  0.0f},
    };
    meshNoInd.m_color = Colors::Green<fcolor3>;
    Poole::Rendering::Renderer::Submit(std::move(meshNoInd));


    Poole::Rendering::StaticMeshNoIndiciesSolidColor3_2DTransform meshNoInd2;
    meshNoInd2.m_verts = std::vector<Poole::Rendering::Vertex>{
        //{-0.5f,  -0.5f,  0.0f},
        //{ 0.5f,  -0.5f,  0.0f},
        //{ 0.0f,   0.5f,  0.0f},

        {-0.75f, -0.75f, 0.0f},
        {-0.25f, -0.75f, 0.0f},
        {-0.5f,  -0.5f,  0.0f},

        //{0.75f, 0.75f, 0.0f},
        //{0.25f, 0.75f, 0.0f},
        //{0.5f,  0.5f,  0.0f},
    };
    meshNoInd2.m_color = Colors::Pink<fcolor3>;
    Poole::Rendering::Renderer::Submit(std::move(meshNoInd2));

    Poole::Rendering::StaticMeshNoIndiciesSolidColor3_2DTransform meshNoInd3;
    meshNoInd3.m_verts = std::vector<Poole::Rendering::Vertex>{
        //{-0.5f,  -0.5f,  0.0f},
        //{ 0.5f,  -0.5f,  0.0f},
        //{ 0.0f,   0.5f,  0.0f},

        //{-0.75f, -0.75f, 0.0f},
        //{-0.25f, -0.75f, 0.0f},
        //{-0.5f,  -0.5f,  0.0f},

        {0.75f, 0.75f, 0.0f},
        {0.25f, 0.75f, 0.0f},
        {0.5f,  0.5f,  0.0f},
    };
    meshNoInd3.m_color = Colors::Cyan<fcolor3>;
    Poole::Rendering::Renderer::Submit(std::move(meshNoInd3));
}
void TestMeshSolidColor()
{
    Poole::Rendering::StaticMeshSolidColor3_2DTransform mesh;
    mesh.m_verts = std::vector<Poole::Rendering::Vertex>{
        {0.9f,   0.3f, 0.0f}, // top right
        {0.9f,  -0.3f, 0.0f}, // bottom right
        {0.6f,  -0.3f, 0.0f}, // bottom left
        {0.6f,   0.3f, 0.0f}, // top left

        //{ 0.9f,  0.9f, 0.0f}, // top right
        //{ 0.9f,  0.7f, 0.0f}, // bottom right
        //{ 0.7f,  0.7f, 0.0f}, // bottom left
        //{ 0.7f,  0.9f, 0.0f}, // top left
    };
    mesh.m_indices = {
        0, 1, 3,   // first triangle
        1, 2, 3,    // second triangle

        //4+0, 4+1, 4+3,   // first triangle
        //4+1, 4+2, 4+3    // second triangle
    };
    mesh.m_color = Colors::Red<fcolor3>;
    Poole::Rendering::Renderer::Submit(std::move(mesh));

    Poole::Rendering::StaticMeshSolidColor3_2DTransform mesh2;
    mesh2.m_verts = std::vector<Poole::Rendering::Vertex>{
        //{0.9f,   0.3f, 0.0f}, // top right
        //{0.9f,  -0.3f, 0.0f}, // bottom right
        //{0.6f,  -0.3f, 0.0f}, // bottom left
        //{0.6f,   0.3f, 0.0f}, // top left

        { 0.9f,  0.9f, 0.0f}, // top right
        { 0.9f,  0.7f, 0.0f}, // bottom right
        { 0.7f,  0.7f, 0.0f}, // bottom left
        { 0.7f,  0.9f, 0.0f}, // top left
    };
    mesh2.m_indices = {
        0, 1, 3,   // first triangle
        1, 2, 3,    // second triangle

        //4+0, 4+1, 4+3,   // first triangle
        //4+1, 4+2, 4+3    // second triangle
    };
    mesh2.m_color = Colors::Orange<fcolor3>;
    Poole::Rendering::Renderer::Submit(std::move(mesh2));
}
void TestMeshVertexColor()
{
    Poole::Rendering::StaticMeshVertexColor3_2DTransform meshWithColor;
    meshWithColor.m_verts = std::vector<Poole::Rendering::VertexWithColor3>{
        {Poole::Rendering::Vertex{0.3f,   0.3f, 0.0f}, /*top right*/      Colors::Yellow<fcolor3>},
        {Poole::Rendering::Vertex{0.3f,  -0.3f, 0.0f}, /*bottom right*/   Colors::Green<fcolor3>},
        {Poole::Rendering::Vertex{-0.3f, -0.3f, 0.0f}, /*bottom left*/    Colors::White<fcolor3>},
        {Poole::Rendering::Vertex{-0.3f,  0.3f, 0.0f}, /*top left*/       Colors::Purple<fcolor3>},

        //{Poole::Rendering::Vertex{-0.7f,  0.9f, 0.0f}, /*top right*/      Colors::Orange<fColor3>},
        //{Poole::Rendering::Vertex{-0.7f,  0.7f, 0.0f}, /*bottom right*/   Colors::Cyan<fColor3>},
        //{Poole::Rendering::Vertex{-0.9f,  0.7f, 0.0f}, /*bottom left*/    Colors::Grey<fColor3>}, 
        //{Poole::Rendering::Vertex{-0.9f,  0.9f, 0.0f}, /*top left*/       Colors::Pink<fColor3>},
    };
    meshWithColor.m_indices = {
        0, 1, 3,   // first triangle
        1, 2, 3,    // second triangle

        //4+0, 4+1, 4+3,   // first triangle
        //4+1, 4+2, 4+3    // second triangle
    };
    Poole::Rendering::Renderer::Submit(std::move(meshWithColor));

    Poole::Rendering::StaticMeshVertexColor3_2DTransform meshWithColor2;
    meshWithColor2.m_verts = std::vector<Poole::Rendering::VertexWithColor3>{
        //{Poole::Rendering::Vertex{0.3f,   0.3f, 0.0f}, /*top right*/      Colors::Yellow<fColor3>},
        //{Poole::Rendering::Vertex{0.3f,  -0.3f, 0.0f}, /*bottom right*/   Colors::Green<fColor3>},
        //{Poole::Rendering::Vertex{-0.3f, -0.3f, 0.0f}, /*bottom left*/    Colors::White<fColor3>},
        //{Poole::Rendering::Vertex{-0.3f,  0.3f, 0.0f}, /*top left*/       Colors::Purple<fColor3>},

        {Poole::Rendering::Vertex{-0.7f,  0.9f, 0.0f}, /*top right*/      Colors::Orange<fcolor3>},
        {Poole::Rendering::Vertex{-0.7f,  0.7f, 0.0f}, /*bottom right*/   Colors::Cyan<fcolor3>},
        {Poole::Rendering::Vertex{-0.9f,  0.7f, 0.0f}, /*bottom left*/    Colors::Grey<fcolor3>},
        {Poole::Rendering::Vertex{-0.9f,  0.9f, 0.0f}, /*top left*/       Colors::Pink<fcolor3>},
    };
    meshWithColor2.m_indices = {
        0, 1, 3,   // first triangle
        1, 2, 3,    // second triangle

        //4+0, 4+1, 4+3,   // first triangle
        //4+1, 4+2, 4+3    // second triangle
    };
    Poole::Rendering::Renderer::Submit(std::move(meshWithColor2));
}

void TempMoveTriangles()
{
    Poole::Rendering::StaticMeshNoIndiciesSolidColor3_2DTransform* Mesh =
        Poole::Rendering::Renderer::GetMesh<Poole::Rendering::StaticMeshNoIndiciesSolidColor3_2DTransform>(0);

    static float P = 0.f;
    P += 0.01f;

    Mesh->m_position = { cosf(P / 5) / 3, sinf(P / 5) / 3 };
    Mesh->m_rotation = P * 0.01f;
    Mesh->m_scale = { (cosf(P / 25) + 2) / 2, (cosf(P / 25) + 2) / 2 };
    Mesh->m_shear = { 0.1, 0.1 };
}

void Sandbox::BeginApp()
{
    TestMeshNoIndiciesSolidColor();
    TestMeshSolidColor();
    TestMeshVertexColor();
}

void Sandbox::UpdateApp(float /*deltaTime*/)
{
   TempMoveTriangles();
}

void Sandbox::EndApp()
{

}
