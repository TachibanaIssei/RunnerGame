#include "stdafx.h"
#include "OptionScreen.h"

bool OptionScreen::Start()
{
  m_position.Set(0.0f, -150.0f, 0.0f);
  m_bgmFont.SetPosition(m_position);
  m_seFont.SetPosition(m_position.x, m_position.y - 50.0f, m_position.z);

  m_bgmFont.SetColor(Vector4::Yellow);
  m_seFont.SetColor(Vector4::Yellow);

  m_bgmVolume = g_gameVolumeManager->GetBGMVolume();
  return true;
}

void OptionScreen::Update()
{
  if (g_pad[0]->IsTrigger(enButtonB))
  {
    Deactivate();
  }

  if (g_pad[0]->IsTrigger(enButtonUp))
  {
    m_bgmVolume += 0.1f;
    g_gameVolumeManager->SetBGMVolume(m_bgmVolume);
    g_gameVolumeManager->SaveVolume();
  }
  if (g_pad[0]->IsTrigger(enButtonDown))
  {
    m_bgmVolume -= 0.1f;
    g_gameVolumeManager->SetBGMVolume(m_bgmVolume);
    g_gameVolumeManager->SaveVolume();
  }

  wchar_t buff[255];
  swprintf_s(buff, 255, L"%2.1f", g_gameVolumeManager->GetBGMVolume());
  m_bgmFont.SetText(buff);
  swprintf_s(buff, 255, L"%2.1f", g_gameVolumeManager->GetSEVolume());
  m_seFont.SetText(buff);
}

void OptionScreen::Render(RenderContext& rc)
{
  m_bgmFont.Draw(rc);
  m_seFont.Draw(rc);
}
