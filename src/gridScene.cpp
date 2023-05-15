

#include <iostream>
#include "threepp/renderers/TextHandle.hpp"
#include "gridScene.hpp"

using namespace threepp;

BoxScene::BoxScene() :
        m_canvas(Canvas::Parameters().size({600, 500})),
        m_renderer(m_canvas),
        m_scene(Scene::create()),
        m_camera(OrthographicCamera::create(0, 6, 0, 6 , 0.1, 1000)),
        m_geometry(BoxGeometry::create()),
        m_material(MeshBasicMaterial::create()),
        m_yellowMaterial(MeshBasicMaterial::create()),
        m_whiteMaterial(MeshBasicMaterial::create()),
        m_boxes(SIZE, std::vector<Box>(SIZE)),
        m_mouseListener(m_canvas),
        m_rd(),
        m_gen(m_rd()),
        m_dis(0, 1)

{
    m_canvas.addMouseListener(&m_mouseListener);
    m_renderer.setClearColor(Color::black);
    m_camera->position.set(0, 0,1);
    m_camera->lookAt(0, 0,0);
    m_material->color = Color::yellow;
    m_whiteMaterial->color.setRGB(1, 1, 1);
    m_yellowMaterial->color.setRGB(1, 1, 0);

    m_canvas.onWindowResize([&](WindowSize size) {
        m_canvas.setSize({600, 500});
    });
}

void BoxScene::createBoxes() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            Box box;
            auto mat = MeshBasicMaterial::create();
            mat->color = Color::yellow;
            auto _mesh = Mesh::create(m_geometry, mat); // x
            _mesh->position.set(    0.1f + _mesh->scale.x*0.5f + static_cast<float>(j)*(_mesh->scale.x+0.1f), // y
                                    0.1f + _mesh->scale.x*0.5f + static_cast<float>(i)*(_mesh->scale.y+0.1f), // z
                                    0.0f);
            box.mesh = _mesh;
            m_boxes[i][j] = box; // assign the box
            m_scene->add(m_boxes[i][j].mesh);
        }
    }
}

void BoxScene::generateValidPattern() {
    int random = math::randomInRange(0, 6); // sets one of the 7 patterns declared to be valid

    std::vector<bool> pattern = m_valids[random];

    for (int j = 0; j < SIZE; j++) {
        if (pattern[j]) {
            m_boxes[4][j].setColor(Color::yellow);
        }
    }

    for (int j = 0; j < 500; j++) {
        int i = math::randomInRange(0, 24);

        int x = i % SIZE; // gives x-coordinate of the yellow boxes
        int y = (i - x) / SIZE; // gives y-coordinate of the yellow boxes

        toggle({x, y}); // toggles the yellow box
    }
}



void BoxScene::animate() {
    m_canvas.addKeyListener(&m_keyListener);
    m_canvas.animate([&](float dt) {
        if (m_keyListener.onResetPressed()){
            generateValidPattern();
        }
        if (m_mouseListener.mouseDown) {
            m_mouseListener.mouseDown = false;
            moves++;
            Vector2 index = getBoxAtPosition(m_mouseListener.realPos);
            if (index.x != -1) {
                toggle(index);
            }
            if (checkWin()) {
                m_renderer.enableTextRendering();
                m_renderer.textHandle("Congratulation!! press (r) to start a new game");
                std::cout<< "Congratulations!! press (r) to start a new game"<< std::endl;
            }
        }
        m_renderer.render(m_scene, m_camera);
    });
}
void BoxScene::run() {
    createBoxes();
    generateValidPattern();
    animate();
}

Vector2 BoxScene::getBoxAtPosition(Vector2 pos) {

    Vector2 boxSizePixels = {100, 83};
    Vector2 spacingSizePixels = {10, 8};


    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            Vector2 boxCanvasPosMin = {
                    spacingSizePixels.x * static_cast<float>(1+j) + boxSizePixels.x * static_cast<float>(j), // x
                    spacingSizePixels.y * static_cast<float>(1+i) + boxSizePixels.y * static_cast<float>(i) // y
            };

            Vector2 boxCanvasPosMax = {
                    spacingSizePixels.x * static_cast<float>(1+j) + boxSizePixels.x * static_cast<float>(j+1), // x
                    spacingSizePixels.y * static_cast<float>(1+i) + boxSizePixels.y * static_cast<float>(i+1) // y
            };


            if (pos.x > boxCanvasPosMin.x && pos.x < boxCanvasPosMax.x && pos.y > boxCanvasPosMin.y && pos.y < boxCanvasPosMax.y) {
                return Vector2{i, j};
            }
        }
    }

    std::cout << pos << std::endl;

    return Vector2{-1, -1};
}
void BoxScene::toggle(Vector2 indexes) {

    int i = static_cast<int>(indexes.x);
    int j = static_cast<int>(indexes.y);


    if (i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
        m_boxes[i][j].toggle();
        if (i > 0)
            m_boxes[i - 1][j].toggle();
        if (i < SIZE - 1)
            m_boxes[i + 1][j].toggle();
        if (j > 0)
            m_boxes[i][j - 1].toggle();
        if (j < SIZE - 1)
            m_boxes[i][j + 1].toggle();
    }

}

bool BoxScene::checkWin() {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (m_boxes[i][j].color == Color::yellow) {
                return false;
            }
        }
    }
    return true;

}

