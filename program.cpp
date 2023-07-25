#include <vector>
#include <string>
#include "program.hpp"
#include "filesystem.hpp"

Program::Program(HINSTANCE instance)
: window(instance), bar(window.getHandle(), instance)
{

}

Program::~Program()
{

}


void Program::run()
{

}
