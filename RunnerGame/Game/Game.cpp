#include "stdafx.h"
#include "Game.h"
#include "UI/ImGuiInGame.h"
#include "Scene/ResultScreen.h"
#include "Player/Player.h"

Game::~Game()
{
  DeleteGO(m_imGuiInGame);
}

bool Game::Start()
{
  m_player = NewGO<Player>(0, "player");
  m_imGuiInGame = NewGO<ImGuiInGame>(0, "imGuiInGame");
	return true;
}

void Game::Update()
{
  GoToResult();
	
}

void Game::Render(RenderContext& rc)
{
	
}

void Game::GoToResult()
{
  if (g_pad[0]->IsTrigger(enButtonSelect))
  {
    NewGO<ResultScreen>(0, "result");
    DeleteGO(this);
  }
}
