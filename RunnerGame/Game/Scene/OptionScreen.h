#pragma once
class OptionScreen:public IGameObject
{
public:
  bool Start()override;
  void Update()override;
  void Render(RenderContext& rc)override;

private:
  FontRender m_bgmFont;
  FontRender m_seFont;
  Vector3 m_position;

  float m_bgmVolume = 0.5f;
};

