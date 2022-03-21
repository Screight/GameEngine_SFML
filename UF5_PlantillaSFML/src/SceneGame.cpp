#include "SceneGame.h"
#include "Singletons.h"
#include <iostream>

SceneGame::SceneGame() : Scene() {};
SceneGame::~SceneGame() {};

void SceneGame::PreLoad() {};

void SceneGame::Initialize() {};

void SceneGame::EarlyUpdate() {};
void SceneGame::Update() {};
void SceneGame::LateUpdate() {};

void SceneGame::EarlyRender() {};
void SceneGame::Render() {};
void SceneGame::LateRender() {};

void SceneGame::RenderGUI() {};