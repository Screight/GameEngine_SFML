#include "SceneGame.h"
#include "Singletons.h"
#include <iostream>

SceneGame::SceneGame() : Scene() {};
SceneGame::~SceneGame() {};

void SceneGame::PreLoad() {
		m_player = new Player();
		mwallImg = g_resourceManager->GetSpriteID("Assets/wall.png");
		loadMap();
};

void SceneGame::Initialize() {
		
};

void SceneGame::EarlyUpdate() {};
void SceneGame::Update() {
		m_player->Update();
};
void SceneGame::LateUpdate() {};

void SceneGame::EarlyRender() {};
void SceneGame::Render() {
		m_player->Render();
		renderMap();
};
void SceneGame::LateRender() {};

void SceneGame::RenderGUI() {};

void SceneGame::loadMap() {
		std::fstream file;
		file.open("Assets/testMap.txt", std::ios::in); //abrimos mapa en formato texto
		if (!file.is_open()) {
				std::cout << "ERROR: Map not found" << std::endl;
				system("pause");
				exit(0);
		}
		std::string line;
		std::getline(file, line);
		mpMapWidth = atoi(line.c_str());
		std::getline(file, line);
		mpMapHeight = atoi(line.c_str());

		mpCollisionMap.resize(mpMapHeight);
		for (int i = 0; i < mpMapHeight; i++) {
				mpCollisionMap[i].resize(mpMapWidth, false);
		}

		int j = 0;
		while (!file.eof()) {
				std::getline(file, line);
				int size = line.size();
				for (int i = 0; i < size; i++) {
						char a_char = line[i];
						bool collision = false;
						switch (a_char) {
						default: break;
						case '#':
								collision = true;
								break;
						case 'P':
								m_player->SetX(i*TILE_SIZE);
								m_player->SetY(j*TILE_SIZE);
								break;
						}
						mpCollisionMap[j][i] = collision;
				}
				j++;
		}
		file.close();
		m_player->SetCollisionMap(&mpCollisionMap);
}

void SceneGame::renderMap() {
		if (mpMapWidth == 0 || mpMapHeight == 0) { return; }
		for (int i = 0; i < mpMapHeight; i++) {
				for (int j = 0; j < mpMapWidth; j++) {
						if (mpCollisionMap[i][j]) {
								g_renderer->DrawSprite(mwallImg, j * TILE_SIZE, i * TILE_SIZE, Color{255,255,255});
						}
				}
		}
}