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
    EXPECT_EQ(arr[1],5);
    EXPECT_EQ(arr[9],5);


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

TEST(custom_array, assignment_operator){

    lib::Array<int> arr1(10,5);
    EXPECT_EQ(arr1.Capacity(),10);
    lib::Array<int>arr2{};
    arr2 = arr1;
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

TEST(custom_array, insert_without_reallocation){

    lib::Array<int> arr1(10,5);
    EXPECT_EQ(arr1.Capacity(),10);
    arr1.Insert(2,100);
    EXPECT_EQ(arr1.Capacity(),20);
    EXPECT_EQ(arr1.Size(),11);
    EXPECT_EQ(arr1[0],5);
    EXPECT_EQ(arr1[2],100);
    EXPECT_EQ(arr1[3],5);
    EXPECT_EQ(arr1[10],5);


}