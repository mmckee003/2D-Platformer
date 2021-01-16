#ifndef WIN32_MAIN_H
#define WIN32_MAIN_H

#include <Windows.h>
#include <wincon.h>

// global from game.h
bool SHOULD_QUIT;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int create_window(HINSTANCE hInstance);
INT WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdLine, _In_ INT nCmdShow);

#endif