#include"get_time.hpp"
#include<ctime>
#include<chrono>


namespace lib
{
    char* getTimeNow(){

        const auto time_now = std::chrono::high_resolution_clock::now();

        const std::time_t time_now_ctime = std::chrono::system_clock::to_time_t(time_now);

        return std::ctime(&time_now_ctime);

    }
} // namespace time_utils
