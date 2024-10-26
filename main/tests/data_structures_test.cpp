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
    EXPECT_EQ(dummy_stack.top(),3);
    dummy_stack.pop();
    dummy_stack.pop();
    dummy_stack.pop();
    dummy_stack.pop();
    dummy_stack.pop();
    //seg-fault: 
    // EXPECT_EQ(dummy_stack.top(),std::nullopt);
}

TEST(queue, positive_test){
    lib::queue<int> dummy_queue;
    dummy_queue.push(5);
    dummy_queue.push(6);
    dummy_queue.push(7);
    dummy_queue.push(8);
    EXPECT_EQ(dummy_queue.front(), 5);
    dummy_queue.pop();
    EXPECT_EQ(dummy_queue.front(), 6);
    dummy_queue.pop();
    EXPECT_EQ(dummy_queue.front(), 7);
    dummy_queue.pop();
    dummy_queue.pop();
    dummy_queue.pop();
}

