#include "stdafx.h"
#include "GameVolumeManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

GameVolumeManager* GameVolumeManager::m_instance = nullptr;
GameVolumeManager* g_gameVolumeManager = nullptr;

GameVolumeManager::~GameVolumeManager()
{
}

void GameVolumeManager::Init()
{
  g_gameVolumeManager = this;
  LoadVolume();
}

void GameVolumeManager::LoadVolume()
{
  std::ifstream file(m_filePath);
  if (!file.is_open()) {
    std::cerr << "Failed to open file: " << m_filePath << std::endl;
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string key;
    float value;
    if (iss >> key >> value) {
      if (key == "BGM") {
        m_bgmVolume = value;
      }
      else if (key == "SE") {
        m_seVolume = value;
      }
    }
  }
  file.close();
}

void GameVolumeManager::SaveVolume()
{
  std::ofstream file(m_filePath);
  if (!file.is_open()) {
    std::cerr << "Failed to open file: " << m_filePath << std::endl;
    return;
  }

  file << "BGM "<< m_bgmVolume << std::endl;
  file << "SE "<< m_seVolume << std::endl;
  file.close();
}
