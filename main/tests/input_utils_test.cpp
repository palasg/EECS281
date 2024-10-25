#include"input_utils.hpp"
#include"sort_algos.hpp"
#include"print_utils.hpp"
#include<gtest/gtest.h>
#include<cassert>
#include<vector>


TEST(file_reading_test, success){

    std::string file_name{"/home/palasg/git_repos/EECS281/main/tests/data/random_text.txt"};
std::ifstream f;

// Set exceptions to be thrown on failure
f.exceptions(std::ifstream::failbit | std::ifstream::badbit);

try {
    f.open(file_name);
    std::string temp{};
    std::vector<std::string>buffer;
    lib::readLines(f,buffer );
    std::cout << temp <<std::endl;
} catch (std::system_error& e) {
    std::cerr << e.code().message() << std::endl;
}
    f.close();
}

TEST(buble_sort, best_case){

    std::vector<int> collection{-3,5,6,1,0,9};
    lib::bubble_sort(collection.begin(), collection.end());
    lib::printVector(collection);

}
