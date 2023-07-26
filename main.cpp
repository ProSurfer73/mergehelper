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
#include "textbox.hpp"

void fileLoading(const std::vector<std::string>& v, ProgressBar& bar, TextBox& box);

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

    TextBox box(window.getHandle());

    //
    std::thread thread(fileLoading, std::cref(v), std::ref(bar), std::ref(box) );


    return window.run();
}

void fileLoading(const std::vector<std::string>& v, ProgressBar& bar, TextBox& box)
{
    char buf[20];

    for(unsigned i=0; i<v.size(); ++i)
    {
        const std::string& s = v[i];

        if(detectFile(s))
            std::cout << s << std::endl;
        bar.increment();

        sprintf(buf, "%u/%u", (i+1), v.size());
        box.setText(buf);
    }
}

