#pragma once
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx12.h"
#include "imgui_internal.h"

class MyimGUI : public IGameObject
{
public:
	void Init();
	void Update()override;
	void Render(RenderContext& rc) override;
private:

};

