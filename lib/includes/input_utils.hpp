#ifndef INPUT_UTILS_HPP
#define INPUT_UTILS_HPP

#include<fstream>
#include<vector>
#include<string>

namespace lib
{

bool readLines(std::ifstream& file_stream, std::vector<std::string>&buffer);
    
} // namespace lib



#endif
