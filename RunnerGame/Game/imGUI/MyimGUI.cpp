#include "stdafx.h"
#include "MyimGUI.h"
#include "system/system.h"

void MyimGUI::Init()
{
	//ImGuiコンテキストの初期化///////////////////////////////////////////////////////
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	///////////////////////////////////////////////////////////////////////////////////

	//ImGuiのウィンドウのスタイルカラー///////////////////////////////////////////////
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();
	//ImGui::StyleColorsClassic();
	///////////////////////////////////////////////////////////////////////////////////

	//backendsの初期化////////////////////////////////////////////////////////////////
	ImGui_ImplWin32_Init(g_hWnd);																		//ウィンドウハンドル
	ImGui_ImplDX12_Init(
		g_graphicsEngine->GetD3DDevice(),																//d3d12デバイスのポインタ
		g_graphicsEngine->GetFrameBufferCount(),														//フレームバッファの数
		DXGI_FORMAT_R8G8B8A8_UNORM,																		//レンダーターゲットビューのフォーマット
		g_graphicsEngine->GetFontEngine().GetSrvDescriptorHeap(),										//SRVのヒープ(フォント用から持ってきた)
		g_graphicsEngine->GetFontEngine().GetSrvDescriptorHeap()->GetCPUDescriptorHandleForHeapStart(),	//フォントテクスチャのCPUディスクリプタハンドル
		g_graphicsEngine->GetFontEngine().GetSrvDescriptorHeap()->GetGPUDescriptorHandleForHeapStart()	//フォントテクスチャのGPUディスクリプタハンドル
	);
	///////////////////////////////////////////////////////////////////////////////////
}

void MyimGUI::Update()
{
}

void MyimGUI::Render(RenderContext& rc)
{
}
