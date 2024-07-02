#include "stdafx.h"
#include "Game.h"
#include "ImGuiInGame.h"

Game::~Game()
{
  DeleteGO(m_imGuiInGame);
}

bool Game::Start()
{
	m_modelRender.Init("Assets/modelData/unityChan.tkm");
  m_imGuiInGame = NewGO<ImGuiInGame>(0, "imGuiInGame");
	return true;
}

void Game::Update()
{
	m_modelRender.Update();
}

void Game::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
