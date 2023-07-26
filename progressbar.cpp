#include <windows.h>
#include <CommCtrl.h>

#include "progressbar.hpp"

ProgressBar::ProgressBar(HWND mainWindow, HINSTANCE g_hinst)
{
    RECT rcClient;
    GetClientRect(mainWindow, &rcClient);

    int cyVScroll = 10;

    m_handle = CreateWindowEx(0, PROGRESS_CLASS, (LPTSTR) NULL,
                            WS_CHILD | WS_VISIBLE | PBS_SMOOTH,
                            0, 0,
                            rcClient.right-rcClient.left , 30,
                            mainWindow, (HMENU) 0, g_hinst, NULL);

    // sets the increment of the progress bar.
    SendMessage(m_handle, PBM_SETSTEP, (WPARAM) 1, 0);
}

void ProgressBar::setRange(unsigned number)
{
    // sets its range
    SendMessage(m_handle, PBM_SETRANGE, 0, MAKELPARAM(0, number));
}

void ProgressBar::increment()
{
    SendMessage(m_handle, PBM_STEPIT, 0, 0);
}
