#pragma once
#include <Windows.h>
#include <cstdint>
#include <string>

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_win32.h"
#include "../imgui/imgui_impl_dx11.h"
#include "../imgui/imgui_internal.h"

using present_t = HRESULT(__stdcall*)(IDXGISwapChain* swap_chain, UINT sync_interval, UINT flags);
using resize_buffers_t = HRESULT(__stdcall*)(IDXGISwapChain* this_ptr, UINT buffer_count, UINT width, UINT height, DXGI_FORMAT new_format, UINT swap_chain_flags);

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace renderer
{
	void init();

	int get_w();
	int get_h();

	RECT get_screen_rect();
}

namespace discord_overlay::addresses
{
	constexpr std::uintptr_t present = 0x14CED4;

	constexpr std::uintptr_t resize_buffers = 0x14CEE8;
}