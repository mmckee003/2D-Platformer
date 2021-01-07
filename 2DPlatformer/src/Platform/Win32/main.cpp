#include <Windows.h>
#include <wincon.h>
#include <iostream>

// windows entry point
INT WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdLine, _In_ INT nCmdShow)
{
    AllocConsole();
    AttachConsole(GetCurrentProcessId());
    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);

    std::cout << "Hello, Sailor!\n";

    while (true) {}

    return 0;
}