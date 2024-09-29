#include<gtest/gtest.h>
#include<get_time.hpp>


TEST(HELLO, Dummy){
    [[maybe_unused]] auto const time_now = time_utils::getTimeNow();
    constexpr int var = 5;
    EXPECT_EQ(var, 5);
}