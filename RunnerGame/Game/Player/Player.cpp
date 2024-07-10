#include "stdafx.h"
#include "Player.h"

bool Player::Start()
{
  Init();
  return true;
}

void Player::Update()
{
  m_modelRender.Update();
}

void Player::Render(RenderContext& rc)
{
  m_modelRender.Draw(rc);
}

void Player::Init()
{
  m_modelRender.Init("Assets/modelData/unityChan.tkm");
}
