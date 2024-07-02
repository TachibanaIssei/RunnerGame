#pragma once
#include <d3d12.h>
#include <dxgi1_4.h>
#include <Windows.h>
#include "imgui.h"
#include "imgui_impl_dx12.h"
#include "imgui_impl_win32.h"

class ImGuiManager
{
public:
	void Init(HWND hwnd, ID3D12Device* device, ID3D12CommandQueue* commandQueue);
	void BeginFrame();
	void EndFrame();
	void Render(ID3D12GraphicsCommandList* commandList);
	void Shutdown();

private:
	ID3D12Device* m_device = nullptr;
	ID3D12DescriptorHeap* m_pd3dSrvDescHeap = nullptr;
};

