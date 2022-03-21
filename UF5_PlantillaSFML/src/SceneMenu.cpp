#include "SceneMenu.h"
#include "Singletons.h"
#include <iostream>

SceneMenu::SceneMenu() : Scene() {};
SceneMenu::~SceneMenu() {};

void SceneMenu::PreLoad() {};

void SceneMenu::Initialize() {
		m_backgroundID = g_resourceManager->GetSpriteID("assets/menu_background.png");
};

void SceneMenu::EarlyUpdate() {};
void SceneMenu::Update() {};
void SceneMenu::LateUpdate() {};

void SceneMenu::EarlyRender() {};
void SceneMenu::Render() {
		g_renderer->DrawSprite(m_backgroundID, 0, 0, C_Rectangle{ 0, 0, 960, 540 }, Color{ 255, 255, 255 });
};
void SceneMenu::LateRender() {};

void SceneMenu::RenderGUI() {};