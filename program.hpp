#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <windows.h>
#include "window.hpp"
#include "progressbar.hpp"

class Program
{
public:
    Program(HINSTANCE instance);
    ~Program();

    void run();

private:
    Window window;
    ProgressBar bar;
};

#endif // PROGRAM_HPP
