#include"custom_array.hpp"
#include<gtest/gtest.h>


TEST(custom_array, zero_initilization){

    lib::Array<int> arr(10);
    EXPECT_EQ(arr.Size(),10);
    ASSERT_NE(arr.Get(), nullptr);
    EXPECT_EQ(arr[0],0);
}


TEST(custom_array, nonzero_initilization){

    lib::Array<int> arr(10,5);
    EXPECT_EQ(arr.Size(),10);
    EXPECT_EQ(arr.Capacity(),10);
    ASSERT_NE(arr.Get(), nullptr);
    EXPECT_EQ(arr[0],5);
}

TEST(custom_array, copy_ctor){

    lib::Array<int> arr1(10,5);
    EXPECT_EQ(arr1.Capacity(),10);
    lib::Array<int>arr2 = arr1;
    EXPECT_EQ(arr2.Size(),10);
    EXPECT_EQ(arr2.Capacity(),10);
    auto p = arr2.Get(); 
    if (p==nullptr)
    {
        std::cerr <<"WTF!! \n";
    }    
    ASSERT_NE(arr2.Get(), nullptr);
    EXPECT_EQ(arr2[0],5);
}