#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <string>

bool detectFile(const std::string& s);

bool loadFile(const char* filepath, std::string& interpr1, std::string& interpr2);


#endif // FILEREADER_HPP
