#include "Scene.h"
#include "Singletons.h"

Scene::Scene() {
		m_isSceneLoaded = false;
};
Scene::~Scene() {};

void Scene::PreLoad() {};
void Scene::OnLoad() {
		if (m_isSceneLoaded) return;
		Initialize();
		g_inputManager->ClearInput();
		m_isSceneLoaded = true;
};
void Scene::OnUpdate() {
		EarlyUpdate();
		Update();
		LateUpdate();
};
void Scene::OnRender() {
		g_renderer->ClearWindow();
		EarlyRender();
		Render();
		LateRender();
		RenderGUI();
		g_renderer->RefreshWindow();
};

void Scene::Initialize() {};

void Scene::EarlyUpdate() {};
void Scene::Update() {};
void Scene::LateUpdate() {};

void Scene::EarlyRender() {};
void Scene::Render() {};
void Scene::LateRender() {};

void Scene::RenderGUI() {};