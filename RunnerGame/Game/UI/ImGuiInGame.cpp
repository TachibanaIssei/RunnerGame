#include "stdafx.h"
#include "ImGuiInGame.h"

bool ImGuiInGame::Start()
{
    return true;
}

void ImGuiInGame::Update()
{
#ifdef K2_DEBUG
  // UIの定義
  ImGui::Begin("RunGame");
  
  ImGui::End();
#endif
}

void ImGuiInGame::Render(RenderContext& rc)
{
}
