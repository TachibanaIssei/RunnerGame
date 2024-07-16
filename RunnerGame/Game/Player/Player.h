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
  /// <summary>
  /// アニメをロードする
  /// </summary>
  void LoadAnimation();
  /// <summary>
  /// アニメーションを再生する
  /// </summary>
  void PlayAnimation();
  /// <summary>
  /// キャラクターステートを管理する
  /// </summary>
  void ManageCharacterState();
  /// <summary>
  /// ステート間の遷移で共通の処理
  /// </summary>
  void OnProcessCommonStateTransition();
  /// <summary>
  /// Idleステートへ遷移したときの処理
  /// </summary>
  void OnProcessIdleStateTransition();
  /// <summary>
  /// Walkステートへ遷移したときの処理
  /// </summary>
  void OnProcessWalkStateTransition();
  /// <summary>
  /// Runステートへ遷移したときの処理
  /// </summary>
  void OnProcessRunStateTransition();
  /// <summary>
  /// Jumpステートへ遷移したときの処理
  /// </summary>
  void OnProcessJumpStateTransition();

private:
  /// <summary>
  /// アニメーションの種類
  /// </summary>
  enum EnAnimationClip
  {
    enAnimationClip_Idle,
    enAnimationClip_Walk,
    enAnimationClip_Run,
    enAnimationClip_Jump,
    enAnimationClip_Num
  };
  /// <summary>
  /// キャラクターの状態
  /// </summary>
  enum EnCharacterState
  {
    enCharacterState_Idle,
    enCharacterState_Walk,
    enCharacterState_Run,
    enCharacterState_Jump,
    enCharacterState_Num
  };


private:
  //モデルのメンバ変数
  ModelRender m_modelRender;
  Vector3 m_position = Vector3::Zero;
  Vector3 m_scale = Vector3::One;
  Quaternion m_rotation = Quaternion::Identity;

  //アニメーション関連のメンバ変数
  AnimationClip m_animationClips[enAnimationClip_Num];
  EnCharacterState m_characterState = enCharacterState_Idle;
};

