#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <windows.h>

class Window
{
public:
    Window(HINSTANCE hInstance);

    inline HWND getHandle() const { return m_handle; }

    WPARAM run();

private:
    HWND m_handle;
};


#endif // WINDOW_HPP
