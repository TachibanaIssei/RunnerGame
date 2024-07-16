#include "stdafx.h"
#include "Player.h"
#include "PlayerConstants.h"

bool Player::Start()
{
  Init();
  return true;
}

void Player::Update()
{
  ManageCharacterState();
  PlayAnimation();
  m_modelRender.Update();
}

void Player::Render(RenderContext& rc)
{
  m_modelRender.Draw(rc);
}

void Player::Init()
{
  LoadAnimation();
  m_modelRender.Init("Assets/modelData/unityChan.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisY);
  Quaternion rotation;
  rotation.SetRotationDegY(180.0f);
  m_modelRender.SetRotation(rotation);
}

void Player::LoadAnimation()
{
  m_animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
  m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
  m_animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
  m_animationClips[enAnimationClip_Walk].SetLoopFlag(true);
  m_animationClips[enAnimationClip_Run].Load("Assets/animData/run.tka");
  m_animationClips[enAnimationClip_Run].SetLoopFlag(true);
  m_animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
  m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);
}

void Player::PlayAnimation()
{
  switch (m_characterState)
  {
  case enCharacterState_Idle:
    m_modelRender.PlayAnimation(enAnimationClip_Idle, IDLE_INTERPOLATE_TIME);
    break;
  case enCharacterState_Walk:
    m_modelRender.PlayAnimation(enAnimationClip_Walk, NON_IDLE_INTERPOLATE_TIME);
    break;
  case enCharacterState_Run:
    m_modelRender.PlayAnimation(enAnimationClip_Run, NON_IDLE_INTERPOLATE_TIME);
    break;
  case enCharacterState_Jump:
    m_modelRender.PlayAnimation(enAnimationClip_Jump, NON_IDLE_INTERPOLATE_TIME);
    break;
  }
}

void Player::ManageCharacterState()
{
  switch (m_characterState)
  {
  case enCharacterState_Idle:
    OnProcessIdleStateTransition();
    break;
  case enCharacterState_Walk:
    OnProcessWalkStateTransition();
    break;
  case enCharacterState_Run:
    OnProcessRunStateTransition();
    break;
  case enCharacterState_Jump:
    OnProcessJumpStateTransition();
    break;
  }
}

void Player::OnProcessCommonStateTransition()
{
  if (g_pad[0]->IsTrigger(enButtonA))
  {
    m_characterState = enCharacterState_Idle;
  }
  else if (g_pad[0]->IsTrigger(enButtonB))
  {
    m_characterState = enCharacterState_Walk;
  }
  else if (g_pad[0]->IsTrigger(enButtonX))
  {
    m_characterState = enCharacterState_Run;
  }
  else if (g_pad[0]->IsTrigger(enButtonY))
  {
    m_characterState = enCharacterState_Jump;
  }
}

void Player::OnProcessIdleStateTransition()
{ 
  OnProcessCommonStateTransition();
}

void Player::OnProcessWalkStateTransition()
{
  OnProcessCommonStateTransition();
}

void Player::OnProcessRunStateTransition()
{ 
  OnProcessCommonStateTransition();
}

void Player::OnProcessJumpStateTransition()
{
  OnProcessCommonStateTransition();
}
