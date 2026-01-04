#ifndef PRINT_UTILS_HPP
#define PRINT_UTILS_HPP

#include<iostream>

namespace lib
{
    template<typename T>
    void printVector(const T& container){
        for ( auto &&i : container)
        {
            std::cout << i<<",";
        }
        std::cout <<"\n";
        
    }

    template<typename T>
    void printLinkedList(const T& linkedlist){
        auto temp = linkedlist.m_head;
        while (temp!= nullptr)
        {
            std::cout << temp->m_data << "," ;
            temp = temp->m_next;
        }
        std::cout << "\n";
        
    }
    
} // namespace lib


#endif