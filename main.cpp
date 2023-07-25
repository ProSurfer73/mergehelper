#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <windows.h>

#include "filesystem.hpp"
#include "filereader.hpp"
#include "progressbar.hpp"
#include "window.hpp"
#include "dialogs.hpp"

ATOM Init_App_Window_class(HINSTANCE);                 //Function to create and fill the Window class structure WNDCLASSEX
BOOL InitInstance(HINSTANCE,int);                      //Create window according to specifics in window class structure
LRESULT CALLBACK WinProc(HWND,UINT,WPARAM,LPARAM);     //Used to process the Messages from Windows to Application

static HWND mainWindow;

//-------------------------- Main Program------------------------------------------------------------------------------------------------------//
int WINAPI WinMain(HINSTANCE hInstance,               //instance of the running program
                   HINSTANCE hPrevInstance,           //Previous Instance of the running Program
                   LPSTR     lpCmdLine,               //Long Pointer to Command line Arguments
                   int       nCmdShow)                //Showing the Window
{
    Window window(hInstance);


    DialogBufferType buffer;

    askForDirectory(window.getHandle(), buffer);

    std::vector<std::string> v;
    explore_directory(buffer, v);

    // lets print the content list of that directory for debugging purposes.
    ProgressBar bar(window.getHandle(), hInstance);
    bar.setRange(v.size());

    for(const std::string& s: v){
        if(detectFile(s))
            std::cout << s << std::endl;
        bar.increment();
    }


    std::thread thread(&Window::run, &window);

    return window.run();
}

