#pragma once
class ImGuiInGame :public IGameObject
{
public:
  bool Start()override;
  void Update()override;
  void Render(RenderContext& rc)override;
private:

};

