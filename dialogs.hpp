#ifndef DIALOGS_HPP
#define DIALOGS_HPP

#include <windows.h>

typedef TCHAR DialogBufferType[MAX_PATH];

bool askForDirectory(HWND parent, TCHAR* buffer);

inline void warningDialog(HWND parent, const char* text, const char* title)
{
    MessageBoxA(parent, "You must select a directory to continue.", NULL, MB_ICONWARNING);
}


#endif // DIALOGS_HPP
