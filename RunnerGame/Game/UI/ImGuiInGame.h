#pragma once
class Player;
class ImGuiInGame :public IGameObject
{

public:
  bool Start()override;
  void Update()override;
  void Render(RenderContext& rc)override;
private:
  Player* m_player = nullptr;
};

