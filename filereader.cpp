#include <fstream>
#include <string>
#include "strings.hpp"
#include "filereader.hpp"

using std::string;


bool detectFile(const std::string& s)
{
    //
    std::ifstream file(s);

    std::string line;

    int step=0;

    while(std::getline(file, line))
    {
        if(startsWith(line,"<<<<<<<"))
        {
            if(step==0)
                step++;
            else
                step=0;
        }
        else if(startsWith(line,"======="))
        {
            if(step==1)
                step++;
            else
                step=0;
        }
        else if(startsWith(line,">>>>>>>"))
        {
            if(step==2)
                return true;
            else
                step=0;
        }
    }

    return false;
}

bool loadFile(const char* filepath, string& interpr1, string& interpr2)
{
    std::ifstream file(filepath);

    if(!file)
        return false;

    std::string line;
    int step=0;

    //
    interpr1.clear();
    interpr2.clear();


    while(std::getline(file, line))
    {
        line += '\n';

        if(step==0 && startsWith(line,"<<<<<<<"))
        {
            step++;
        }
        else if(step==1 && startsWith(line,"======="))
        {
            step++;
        }
        else if(step!=2 && startsWith(line,">>>>>>>"))
        {
            step=0;
        }
        else
        {
            if(step==0)
            {
                interpr1 += line;
                interpr2 += line;
            }
            else if(step==1)
            {
                interpr1 += line;
            }
            else if(step==2)
            {
                interpr2 += line;
            }
        }
    }

    return true;
}

