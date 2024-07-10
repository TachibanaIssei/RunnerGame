#pragma once
class Player :public IGameObject
{
public:
  bool Start()override;
  void Update()override;
  void Render(RenderContext& rc)override;

private:
  /// <summary>
  /// 初期化
  /// </summary>
  void Init();

private:
  ModelRender m_modelRender;
  Vector3 m_position = Vector3::Zero;
  Vector3 m_scale = Vector3::One;
  Quaternion m_rotation = Quaternion::Identity;
};

