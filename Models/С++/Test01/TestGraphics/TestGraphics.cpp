#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <Windows.h>
#define mult_y 30


double sinx(double _x) {
    return sin(_x * M_PI / 180);
}


int main() {
    // Получаем дескрипторы для рисования
    HWND hWnd = GetConsoleWindow();
    HDC hDC = GetDC(hWnd);
    // задаем то, чем рисуем
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    SelectObject(hDC, hPen);
    // рисуем линию из позиции (100, 100) в (200, 200), а потом в (300, 200)
    MoveToEx(hDC, 100, 100, NULL);
    LineTo(hDC, 200, 200);
    LineTo(hDC, 300, 200);
    std::cin.get();

    // При завершении работы необходимо освободить ресурсы
    DeleteObject(hPen);
    ReleaseDC(hWnd, hDC);    system("pause");
    return 0;
}
