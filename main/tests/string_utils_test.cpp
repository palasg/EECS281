#include "string_utils.hpp"
#include <gtest/gtest.h>

TEST(string_search_brute_force, positive)
{

    std::string_view original = "hello";
    std::string_view target = "lo";
    auto compare_result = lib::string_search_brute_force(original, target);
    std::cout << "compare result" << compare_result;
    EXPECT_EQ(compare_result, 3);
    target = "ll";
    compare_result = lib::string_search_brute_force(original, target);
    EXPECT_EQ(compare_result, 2);
}

TEST(string_search_rabin_karp, positive)
{

    std::string_view original = "hello";
    std::string_view target = "lo";
    auto compare_result = lib::string_search_Rabin_karp(original, target);
    EXPECT_EQ(compare_result, 3);
    target = "ll";
    compare_result = lib::string_search_brute_force(original, target);
    EXPECT_EQ(compare_result, 2);
}