#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include<string_view>

namespace lib
{
    
    int string_search_brute_force(std::string_view entire_string, std::string_view target_string);
    int string_search_Rabin_karp(std::string_view main_string, std::string_view target_string);
} // namespace lib

#endif