#include <fstream>
#include "strings.hpp"
#include "filereader.hpp"


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
