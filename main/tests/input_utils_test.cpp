#include "input_utils.hpp"
#include "sort_algos.hpp"
#include "print_utils.hpp"
#include <gtest/gtest.h>
#include <cassert>
#include <vector>
#include<cstdlib>

TEST(file_reading_test, success)
{
    std::string file_relative_path = {"/_main/main/tests/data/random_text.txt"};
    std::ifstream f;

    const char* test_dir = std::getenv("TEST_SRCDIR");
    std::cerr<< "TEST_SRCDIR" << test_dir <<std::endl;

    std::string file_path = std::string(test_dir) + file_relative_path;

    std::cerr << "File path : " << file_path <<std::endl;

    // Set exceptions to be thrown on failure
    f.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        f.open(file_path);
        std::string temp{};
        std::vector<std::string> buffer;
        lib::readLines(f, buffer);
        std::cout << temp << std::endl;
    }
    catch (std::system_error &e)
    {
        std::cerr << e.code().message() << std::endl;
    }
    f.close();
}

TEST(buble_sort, best_case)
{

    std::vector<int> collection{-3, 5, 6, 1, 0, 9};
    lib::bubble_sort(collection.begin(), collection.end());
    lib::printVector(collection);
}
