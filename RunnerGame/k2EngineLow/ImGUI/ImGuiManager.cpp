#include "k2EngineLowPreCompile.h"
#include "ImGuiManager.h"

void ImGuiManager::Init(HWND hwnd, ID3D12Device* device, ID3D12CommandQueue* commandQueue)
{
	m_device = device;

    // ImGuiのコンテキストを作成
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.Fonts->AddFontDefault();
    io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

    // スタイルの設定
    //ImGui::StyleColorsDark();
    ImGui::StyleColorsLight();
    //ImGui::StyleColorsClassic();

    // デスクリプタヒープの設定
    D3D12_DESCRIPTOR_HEAP_DESC desc = {};
    desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    desc.NumDescriptors = 1;
    desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
    m_device->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&m_pd3dSrvDescHeap));

    // バックエンドの初期化
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX12_Init(m_device, 2, DXGI_FORMAT_R8G8B8A8_UNORM, m_pd3dSrvDescHeap,
        m_pd3dSrvDescHeap->GetCPUDescriptorHandleForHeapStart(),
        m_pd3dSrvDescHeap->GetGPUDescriptorHandleForHeapStart());
}

void ImGuiManager::BeginFrame()
{
    ImGui_ImplDX12_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

void ImGuiManager::EndFrame()
{
    ImGui::Render();
}

void ImGuiManager::Render(ID3D12GraphicsCommandList* commandList)
{
    ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), commandList);
}

void ImGuiManager::Shutdown()
{
    ImGui_ImplDX12_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
}
