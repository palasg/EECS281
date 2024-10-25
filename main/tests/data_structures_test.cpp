#include"stacks_queues.hpp"
#include<gtest/gtest.h>
#include<iostream>




TEST(stack, positive)
{
    lib::stack<int> dummy_stack{};
    dummy_stack.push(1);
    dummy_stack.push(3);
    dummy_stack.push(4);
    // first need to check if .top has value as it is optional
    //else UB for example see last EXPECT_EQ
    EXPECT_EQ(dummy_stack.top(),4);
    dummy_stack.pop();
    std::cout << "Hello there";
    EXPECT_EQ(dummy_stack.top(),3);
    dummy_stack.pop();
    dummy_stack.pop();
    dummy_stack.pop();
    dummy_stack.pop();
    dummy_stack.pop();
    //seg-fault: 
    // EXPECT_EQ(dummy_stack.top(),std::nullopt);


}

