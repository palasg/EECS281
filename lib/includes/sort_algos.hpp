#ifndef SORT_ALGOS_HPP
#define SORT_ALGOS_HPP
#include <type_traits>
#include <iterator>
#include <iostream>

namespace lib
{

    /// sort algorithms
    template <typename itr_begin, typename = std::_RequireInputIter<itr_begin>>
    void bubble_sort(itr_begin first, itr_begin last)
    {
        auto const length = std::distance(first, last);
        for (int i = 0; i < length; i++)
        {
            bool swap = false;
            for (int j = 0; j < length; j++)
            {
                if (*(first + j) > *(first + i))
                {
                    std::swap(*(first + i), *(first + j));
                    swap = true;
                }
            } // for j
            if (not swap)
            {
                break;
            }
        }
    }

    template <typename itr_begin, typename = std::_RequireInputIter<itr_begin>>
    void selection_sort(itr_begin first, itr_begin last)
    {
        const std::size_t length = std::distance(first, last);
        for (size_t i = 0; i < length; i++)
        {
            // find min
            std::size_t min_index = i;
            for (size_t j = i + 1; j < length; j++)
            {
                if (*(first + min_index) > *((first + j)))
                {
                    min_index = j;
                }
            }
            std::swap(*(first + i), *(first + min_index));
        } // for i
    }

    template <typename itr_begin, typename = std::_RequireInputIter<itr_begin>>
    void insertion_sort(itr_begin first, itr_begin last)
    {
        const int length = std::distance(first, last);
        for (int i = 1; i < length; i++)
        {
            size_t current_position = i;
            for (int j = i - 1; j >= 0; j--)
            {
                if (*(first + current_position) < *(first + j))
                {
                    std::swap(*(first + current_position), *(first + j));
                    current_position = j;
                }
            }
        }
    }

    template <typename T>
    size_t partitioned(std::vector<T> &collection, size_t left, size_t right)
    {
        size_t pivot = right; 
        right = right-1;
        while (true)
        {
            while (collection[left] < collection[pivot])
            {
                left = left +1;
            }
            while (collection[right] > collection[pivot])
            {
                right = right-1;
            }
            if (left > right)
            {
                std::swap(collection[left], right);
            }
            if(left==right){
                std::swap(collection[pivot], collection[right]);
                pivot = right;
                break;
            }
        }
        return pivot;
        
    }

} // namespace lib

#endif