#include "stdafx.h"
#include "Title.h"
#include "OptionScreen.h"
#include "Game.h"

Title::~Title()
{
  DeleteGO(m_optionScreen);
}

bool Title::Start()
{
  m_titleLevel2D.Init("Assets/sprite/outputData/title/titleLevel2D.casl",nullptr);

  m_optionScreen = NewGO<OptionScreen>(0, "optionScreen");
  m_optionScreen->Deactivate();
  return true;
}

void Title::Update()
{
  CheckAndActivateOptionScreen();
  GoToGame();

  m_titleLevel2D.Update();
}

void Title::Render(RenderContext& rc)
{
  m_titleLevel2D.Draw(rc);
}

void Title::CheckAndActivateOptionScreen()
{
  if (g_pad[0]->IsTrigger(enButtonSelect))
  {
    m_optionScreen->Activate();
  }
  if (m_optionScreen->IsActive())
  {
    return;
  }
}

void Title::GoToGame()
{
  if (g_pad[0]->IsTrigger(enButtonA))
  {
    NewGO<Game>(0, "game");
    DeleteGO(this);
  }
}