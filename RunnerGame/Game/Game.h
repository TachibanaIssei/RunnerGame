#pragma once

#include "Level3DRender/LevelRender.h"

class ImGuiInGame;

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
  ImGuiInGame* m_imGuiInGame;
	ModelRender m_modelRender;
	Vector3 m_pos;
};

