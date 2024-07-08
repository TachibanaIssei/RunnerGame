#pragma once
#include "level2DRender/Level2DRender.h"

class Title :public IGameObject
{
public:
  bool Start() override;
  void Update() override;
  void Render(RenderContext& rc)override;

private:
  Level2DRender m_titleLevel2D;
};

