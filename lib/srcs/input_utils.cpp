#include"input_utils.hpp"
#include<iostream>


namespace lib
{

bool readLines(std::ifstream& file_stream, std::vector<std::string>&buffer){
   std::string temp_string{};
   if (not file_stream.is_open())
   {
   std::cerr << "The file is not open" << std::endl;
    return false;
   }
   try{
    while (std::getline(file_stream,temp_string))
    {
        buffer.emplace_back(temp_string);
    }
   }
   catch(std::system_error& e) {
    std::cerr << e.code().message() << std::endl;
}

for (const auto& line: buffer)
{
   std::cout << line <<std::endl;
}


    if (not file_stream.good())
    {
        std::cout<<"the file state is not good";
        file_stream.clear();
        return false;
    }
    return true;
    
    
}
    
} // namespace lib
