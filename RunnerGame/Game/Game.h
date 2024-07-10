#pragma once

#include "Level3DRender/LevelRender.h"

class ImGuiInGame;
class Player;

class Game : public IGameObject
{
public:
  Game() {}
  ~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
  void GoToResult();

private:
  Player* m_player = nullptr;
  ImGuiInGame* m_imGuiInGame = nullptr;
	ModelRender m_modelRender;
	Vector3 m_pos;
};

