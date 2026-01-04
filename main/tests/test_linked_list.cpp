#include "linked_list.hpp"
#include"print_utils.hpp"
#include <gtest/gtest.h>

TEST(Dlinked_list, initialization) {
  lib::DLinkedList<int> ll{};
  EXPECT_EQ(ll.Size(), 0);
  ll.Insert(0, 1); //[1]
  ll.Insert(1, 22);  //[1][22]
  ll.Insert(2, 33);//[1][22][33]
  ll.Insert(3, 44);//[1][22][33][44]
  ll.Insert(4, 55);//[1][22][33][44][55]
  ll.Insert(5, 66);//[1][22][33][44][55][66]
  ll.SortedInsertion(0);//[0][1][22][33][44][55][66]
  ll.SortedInsertion(30);//[0][1][22][30][33][44][55][66]
  ll.SortedInsertion(33);//[0][1][22][30][33][33][44][55][66]
  ll.SortedInsertion(77);//[0][1][22][30][33][33][44][55][66][77]

  // lib::printLinkedList(ll);

  EXPECT_EQ(ll.Size(), 10);
  EXPECT_EQ(ll.front(), 0);
  EXPECT_EQ(ll.back(), 77);
  EXPECT_EQ(ll[3],30);
  EXPECT_EQ(ll[0],0);
  EXPECT_EQ(ll[2],22);
}

TEST(SLinked_list, init){
  lib::SLinkedList<int> slinked_list{};
  slinked_list.Append(11);
  slinked_list.Append(22);

  slinked_list.Append(33);
  slinked_list.Append(44);

  slinked_list.Append(55);
  
  EXPECT_EQ(slinked_list[0],11);
  EXPECT_EQ(slinked_list[2],33);

  lib::ReverseList(slinked_list);


  EXPECT_EQ(slinked_list[0],55);
  EXPECT_EQ(slinked_list[1],44);
  EXPECT_EQ(slinked_list[4],11);

  lib::ReverseLinkedListOptimizedIterative(slinked_list);
  EXPECT_EQ(slinked_list[0],11);
  EXPECT_EQ(slinked_list[1],22);
  EXPECT_EQ(slinked_list[4],55);

  slinked_list.Append(66);
  slinked_list.Append(77);
  slinked_list.Append(88);// 11,22,33,44,55,66,77,88,
  lib::printLinkedList(slinked_list);
  const auto n_elem = lib::Find_nth_ElementFromEnd(slinked_list,2);
  const auto middle = lib::GetMiddleElement(slinked_list);

  EXPECT_EQ(n_elem,77);
  EXPECT_EQ(middle,55);


}