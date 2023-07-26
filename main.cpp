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

void fileLoading(std::vector<std::string>& v, ProgressBar& bar, TextBox& box, std::vector<std::string>& umf, Window& window, TextBox& box2);

//-------------------------- Main Program------------------------------------------------------------------------------------------------------//
int WINAPI WinMain(HINSTANCE hInstance,               //instance of the running program
                   HINSTANCE hPrevInstance,           //Previous Instance of the running Program
                   LPSTR     lpCmdLine,               //Long Pointer to Command line Arguments
                   int       nCmdShow)                //Showing the Window
{
    Window window(hInstance);


    DialogBufferType buffer;

    askForDirectory(window.getHandle(), buffer);

    std::vector<std::string> v, umf;
    explore_directory(buffer, v);

    // lets print the content list of that directory for debugging purposes.
    ProgressBar bar(window.getHandle(), hInstance);
    bar.setRange(v.size());

    TextBox box(window.getHandle(), 20, 230, 80, 300, nullptr, false);

    char buf2[255+50];
    sprintf(buf2, "loading folder: %s", buffer);
    TextBox box2(window.getHandle(), 30, 10, 30, 300, 0, false);
    box2.setText(buf2);

    //
    std::thread thread(fileLoading, std::ref(v), std::ref(bar), std::ref(box), std::ref(umf), std::ref(window), std::ref(box2));


    return window.run();
}

void fileLoading(std::vector<std::string>& v, ProgressBar& bar, TextBox& box, std::vector<std::string>& umf, Window& window, TextBox& box2)
{
    char buf[150];

    for(unsigned i=0; i<v.size(); ++i)
    {
        const std::string& s = v[i];

        if(detectFile(s))
        {
            umf.emplace_back( std::move(v[i]) );
        }
        bar.increment();

        sprintf(buf, "number of files scanned: %u/%u\nnumber of unmerged files found: %u", (i+1), (unsigned)v.size(), (unsigned)umf.size());
        box.setText(buf);
    }

    if(umf.empty())
    {
        warningDialog(window.getHandle(), "There is no unmerged files in that directory.\nPlease select another directory.", NULL);
    }
    else
    {
        // lets launch the second part of our program.
        box.hide();
        box2.hide();
        bar.hide();

        TextBox contFile1(window.getHandle(), 10, 10, 300, 200, "i am the 1st file", true);
        TextBox contFile2(window.getHandle(), 220, 10, 300, 200, "i am the 2nd file", true);
        contFile1.show();
        contFile2.show();

        window.update();

        std::string s1, s2;

        for(unsigned i=0; i<umf.size(); i++)
        {
            loadFile(umf[i].c_str(), s1, s2);
            loadFile(umf[i].c_str(), s1, s2);

            std::cout << "c1:" << s1 << std::endl;

            contFile1.setText(s1.substr(0,100).c_str());
            contFile2.setText(s2.substr(0,100).c_str());

            contFile1.show();
        contFile2.show();

        window.update();

            Sleep(5000);

        }

    }
}

