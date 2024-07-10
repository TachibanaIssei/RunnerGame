#pragma once
#include "level2DRender/Level2DRender.h"

class ResultScreen:public IGameObject
{
public:
  bool Start()override;
  void Update()override;
  void Render(RenderContext& rc)override;
private:
  void Init();
  void GoToTitle();

private:
  Level2DRender m_resultLevel2D;
};

