#include "stdafx.h"
#include "ImGuiInGame.h"
#include "Player/Player.h"

bool ImGuiInGame::Start()
{
  //m_player = FindGO<Player>("player");
  return true;
}

void ImGuiInGame::Update()
{
#ifdef K2_DEBUG
  // UIの定義
  /*ImGui::Begin("RunGame");
  
  ImGui::End();*/
#endif
}

void ImGuiInGame::Render(RenderContext& rc)
{
}
