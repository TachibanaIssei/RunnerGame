#include "stdafx.h"
#include "ResultScreen.h"
#include "Title.h"

bool ResultScreen::Start()
{
  Init();
  return true;
}

void ResultScreen::Update()
{
  GoToTitle();
  m_resultLevel2D.Update();
}

void ResultScreen::Render(RenderContext& rc)
{
  m_resultLevel2D.Draw(rc);
}

void ResultScreen::Init()
{
  m_resultLevel2D.Init("Assets/sprite/outputData/result/resultLevel2D.casl", nullptr);
}

void ResultScreen::GoToTitle()
{
  if (g_pad[0]->IsTrigger(enButtonSelect))
  {
    NewGO<Title>(0, "title");
    DeleteGO(this);
  }
}
