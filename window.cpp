#include <windows.h>
#include "window.hpp"

#define APPTITLE "Merge helper."

//---------Windows Call Back function to Process Messages from Windows-------------------------------------------------------------------------//

LRESULT CALLBACK WinProc (HWND hWnd,           // Window handle
                          UINT message,        // messages from Windows like WM_DESTROY,WM_PAINT
                          WPARAM wParam,       //
                          LPARAM lParam)
{
    switch(message)
    {

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    }
    return DefWindowProc(hWnd,message,wParam,lParam);
}


//Function to create and fill the Window class structure WNDCLASSEX
ATOM Init_App_Window_class(HINSTANCE hInstance)
{
    WNDCLASSEX wc;   //define wc as a structure of type WNDCLASSEX
    // Fill up the structure

    wc.cbSize        =  sizeof(WNDCLASSEX);                   //Size of the structure
    wc.style         =  CS_HREDRAW | CS_VREDRAW;              //Redraw if Size Changes
    wc.lpfnWndProc   =  (WNDPROC)WinProc;                     //Points to the Window Procedure" LRESULT CALLBACK WinProc (,,,,);"
    wc.cbClsExtra    =  0;                                    //No Extra Class Memory
    wc.cbWndExtra    =  0;                                    //No Extra Window Memory
    wc.hInstance     =  hInstance;                            //Handle to the instance
    wc.hIcon         =  NULL;                                 //No Icon
    wc.hCursor       =  LoadCursor(NULL,IDC_ARROW);           //Predefined Arrow
    wc.hbrBackground =  (HBRUSH) GetStockObject(WHITE_BRUSH); //Back ground Color
    wc.lpszMenuName  =  NULL;                                 //No Menu
    wc.lpszClassName =  APPTITLE;                             //Name of Window Class
    wc.hIconSm       =  NULL;

    return RegisterClassEx(&wc); //Register the Window class with OS
}


Window::Window(HINSTANCE hInstance)
{
    Init_App_Window_class(hInstance);

    m_handle = CreateWindow( APPTITLE,      // Window Class Name
                         APPTITLE,            // Title Bar
                         WS_OVERLAPPEDWINDOW, // Window style
                         CW_USEDEFAULT,       // x position of Window
                         CW_USEDEFAULT,       // y position of Window
                         500,                 // Width of the Window
                         400,                 // Height of the Window
                         NULL,                // Parent Window
                         NULL,                // Menu
                         hInstance,           // Application Instance
                         NULL );              // Window parameters


}

WPARAM Window::run()
{
    MSG m;

    ShowWindow(m_handle,1);  //show the Window
    UpdateWindow(m_handle);         //update the window in response to events

    while(GetMessage(&m,NULL,0,0))        //Get message from Application Message Queue,Quit loop on Recieving WM_QUIT
    {
        TranslateMessage(&m);         // Translate Message
        DispatchMessage(&m);          // Dispatch Message to WinProc() function
    }

    return m.wParam;
}
