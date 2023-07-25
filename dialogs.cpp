#include "dialogs.hpp"

#include <Shlobj.h>

bool askForDirectory(HWND parent, TCHAR* buffer)
{
    // select a folder using windows dialog boxes.
    BROWSEINFO bInfo;
    bInfo.hwndOwner = parent;
    bInfo.pidlRoot = NULL;
    bInfo.pszDisplayName = buffer; // Address of a buffer to receive the display name of the folder selected by the user
    bInfo.lpszTitle = "Please, select a folder"; // Title of the dialog
    bInfo.ulFlags = 0 ;
    bInfo.lpfn = NULL;
    bInfo.lParam = 0;
    bInfo.iImage = -1;

    reaskFolder:
    LPITEMIDLIST lpItem = SHBrowseForFolder( &bInfo);
    if( lpItem != NULL )
    {
      SHGetPathFromIDList(lpItem, buffer );
      //......
      return true;
    }

    return false;
}
