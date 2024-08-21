#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    
    const char CLASS_NAME[] = "ConfigRD";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(17);
    
    RegisterClass(&wc);
    
    HWND hwnd = CreateWindowEx(
        0,                             
        CLASS_NAME,                    
        "Config de Ambiente",    
        WS_POPUPWINDOW | WS_BORDER | WS_CAPTION, // Estilo atualizado
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 300,

        NULL,       // Janela pai
        NULL,       // Menu
        hInstance,  // Instância
        NULL        // Parâmetros adicionais
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {        

            
            HWND hButton1 = CreateWindow(
                "BUTTON", "Instalar Config macOS ",
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                150, 100, 200, 40,
                hwnd, (HMENU)1, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

            HWND hButton2 = CreateWindow(
                "BUTTON", "Instalar Config Linux",
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                150, 150, 200, 40,
                hwnd, (HMENU)2, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
        }
        break;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}
