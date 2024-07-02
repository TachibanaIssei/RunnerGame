#include "stdafx.h"
#include "Game.h"

bool Game::Start()
{
	m_modelRender.Init("Assets/modelData/unityChan.tkm");
	
	return true;
}

void Game::Update()
{
	// g_renderingEngine->DisableRaytracing();
	m_modelRender.Update();

  // UIの定義
  ImGui::Begin("Model Position Adjuster");
  static float position[3] = { m_pos.x, m_pos.y, m_pos.z };
  if (ImGui::DragFloat3("Position", position, 0.1f)) {
    m_pos = { position[0],position[1], position[2] };
    m_modelRender.SetPosition(m_pos);
  }
  ImGui::End();
}

void Game::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
