#include "stdafx.h"
#include "Title.h"

bool Title::Start()
{
  m_titleLevel2D.Init("Assets/sprite/outputData/title/titleLevel2D.casl",nullptr);
  return true;
}

void Title::Update()
{
  m_titleLevel2D.Update();
}

void Title::Render(RenderContext& rc)
{
  m_titleLevel2D.Draw(rc);
}
