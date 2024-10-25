#ifndef PRINT_UTILS_HPP
#define PRINT_UTILS_HPP

#include<iostream>

namespace lib
{
    template<typename T>
    void printVector(const T& container){
        for ( auto &&i : container)
        {
            std::cout << i<<",";
        }
        std::cout <<"\n";
        
    }
    
} // namespace lib


#endif