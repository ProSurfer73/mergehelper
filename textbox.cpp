#include <windows.h>

#include "textbox.hpp"

TextBox::TextBox(HWND parent)
{
    handle = CreateWindow("STATIC",
                          "Hello world.",
                          WS_VISIBLE | WS_CHILD,
                          20, 80,
                          300,
                          100,
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
