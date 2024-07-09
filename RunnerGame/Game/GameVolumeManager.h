#pragma once
/// <summary>
/// BGMとSEの音量を設定・保存します。
/// CSVから読み取り、保存します。
/// </summary>
class GameVolumeManager
{
private:
  GameVolumeManager() {}
  ~GameVolumeManager();

  void Init();

public:
  static void CreateInstance()
  {
    m_instance = new GameVolumeManager;
    m_instance->Init();
  }
  static void DeleteInstance()
  {
    delete m_instance;
  }
  static GameVolumeManager* GetInstance()
  {
    return m_instance;
  }

  void LoadVolume();
  void SaveVolume();

  void SetBGMVolume(float volume)
  {
    m_bgmVolume = volume;
  }
  void SetSEVolume(float volume)
  {
    m_seVolume = volume;
  }
  float GetBGMVolume()const
  {
    return m_bgmVolume;
  }
  float GetSEVolume()const
  {
    return m_seVolume;
  }

private:
  static GameVolumeManager* m_instance;

  const std::string m_filePath = "Assets/optionData/gameVolume.csv";
  float m_bgmVolume = 0.5f;
  float m_seVolume = 0.5f;
};

extern GameVolumeManager* g_gameVolumeManager;
