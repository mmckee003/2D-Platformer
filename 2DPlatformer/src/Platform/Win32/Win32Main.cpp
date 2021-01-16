#include "Win32Main.h"
#include <iostream>

#include "src/game.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;
    switch (uMsg)
    {
        case WM_SIZE:
        {
            OutputDebugStringA("WM_SIZE\n");
        } break;
        case WM_DESTROY:
        {
            OutputDebugStringA("WM_DESTROY\n");
            SHOULD_QUIT = true;
        } break;
        case WM_CLOSE:
        {
            OutputDebugStringA("WM_CLOSE\n");
            SHOULD_QUIT = true;
        } break;
        case WM_ACTIVATEAPP:
        {
            OutputDebugStringA("WM_ACTIVATEAPP\n");
        } break;
        default:
        {
            // OutputDebugStringA("default\n");
            result = DefWindowProc(hwnd, uMsg, wParam, lParam);
        }break;
    }
    return result;
}

int create_window(HINSTANCE hInstance)
{
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    // TODO: check if style flags actually do anything
    wc.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hIcon = NULL;
    wc.lpszClassName = L"2DPlatformerWindowClass";
    wc.hIconSm = NULL;
 
    if (RegisterClassEx(&wc))
    {
        HWND hwnd = CreateWindowEx(
            0,
            L"2DPlatformerWindowClass",
            L"2D Platformer",
            WS_OVERLAPPEDWINDOW|WS_VISIBLE,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            0,
            0,
            hInstance,
            0);
        if (hwnd)
        {
            /*
            MSG message; 
            for (;;)
            {
                BOOL message_result = GetMessage(&message, 0, 0, 0);
                if (message_result > 0)
                {
                    TranslateMessage(&message);
                    DispatchMessage(&message);
                }
                else
                {
                    break;
                }
            }
            */

            return 1;

        }
        else
        {
            // TODO: log some error message
        }
    }
    else
    {
        // TODO: log some error message
    }
    return 1;
}

// windows entry point
INT WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdLine, _In_ INT nCmdShow)
{
    // create debug console
    AllocConsole();
    AttachConsole(GetCurrentProcessId());
    FILE* f1 = freopen("CON", "w", stdout);
    FILE* f2 = freopen("CON", "w", stderr);

    create_window(hInstance);

    std::cout << "Win32 Initialized!\n";

    game_update();

    return 0;
}