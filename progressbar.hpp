#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP

#include <windows.h>

class ProgressBar
{
public:
    ProgressBar(HWND mainWindow, HINSTANCE g_hinst);

    void setRange(unsigned number);

    void increment();

    void hide();
    void show();

private:
    HWND m_handle;

};

#endif // PROGRESSBAR_HPP
