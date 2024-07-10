#include "stdafx.h"
#include "Game.h"
#include "ImGuiInGame.h"
#include "ResultScreen.h"

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
  GoToResult();
	m_modelRender.Update();
}

void Game::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}

void Game::GoToResult()
{
  if (g_pad[0]->IsTrigger(enButtonSelect))
  {
    NewGO<ResultScreen>(0, "result");
    DeleteGO(this);
  }
}
