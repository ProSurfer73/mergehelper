#include <windows.h>

#include "textbox.hpp"

TextBox::TextBox(HWND parent, int x, int y, int height, int width, const char* text, bool editable)
{
    handle = CreateWindow(editable?"EDIT":"STATIC",
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

void TextBox::show()
{
    ShowWindow(handle, SW_SHOW);
}

void TextBox::hide()
{
    ShowWindow(handle, SW_HIDE);
}
