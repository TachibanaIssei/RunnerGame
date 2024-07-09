#pragma once
#include "level2DRender/Level2DRender.h"

class OptionScreen;

class Title :public IGameObject
{
public:
  Title() {}
  ~Title();

  bool Start() override;
  void Update() override;
  void Render(RenderContext& rc)override;

private:
  /// <summary>
  /// オプション画面がアクティブかどうかを見る
  /// </summary>
  void CheckAndActivateOptionScreen();

private:
  Level2DRender m_titleLevel2D;
  OptionScreen* m_optionScreen = nullptr;
  
};

