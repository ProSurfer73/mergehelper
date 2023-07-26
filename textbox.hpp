#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include "windows.h"

class TextBox
{
public:
    TextBox(HWND parent, int x, int y, int height, int width, const char* text);
    HWND getHandle() const;

    void setText(const char* text);

private:
    HWND handle;
};


#endif // TEXTBOX_HPP
