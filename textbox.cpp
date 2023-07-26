#include <windows.h>

#include "textbox.hpp"

TextBox::TextBox(HWND parent, int x, int y, int height, int width, const char* text)
{
    handle = CreateWindow("STATIC",
                          text,
                          WS_VISIBLE | WS_CHILD,
                          x, y,
                          width,
                          height,
                          parent,
                          NULL,
                          NULL,
                          NULL);
}

HWND TextBox::getHandle() const
{
    return handle;
}

void TextBox::setText(const char* text)
{
    SetWindowTextA(handle, text);
}
