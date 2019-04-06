#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// __declspec(dllexport)
DWORD WINAPI MessageBoxThread(LPVOID lpParam)
{
	MessageBoxW(NULL, L"Text", L"Caption", NULL);
	return 0;
}

__declspec(dllexport) void __cdecl msg(void);
void msg(void)
{
	CreateThread(NULL, NULL, MessageBoxThread, NULL, NULL, NULL);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved)
{
	switch (ul_reason_for_call){
	case DLL_PROCESS_ATTACH:
		OutputDebugString(L"DLL_PROCESS_ATTACH");
		break;
	case DLL_THREAD_ATTACH:
		OutputDebugString(L"DLL_THREAD_ATTACH");
		break;
	case DLL_THREAD_DETACH:
		OutputDebugString(L"DLL_THREAD_DETACH");
		break;
	case DLL_PROCESS_DETACH:
		OutputDebugString(L"DLL_PROCESS_DETACH");
		break;
	}
	return TRUE;
}
