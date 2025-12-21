#ifndef SORT_ALGOS_HPP
#define SORT_ALGOS_HPP
#include <type_traits>
#include <iterator>
#include<iostream>

namespace lib
{

    template <typename itr_begin, typename = std::_RequireInputIter<itr_begin>>
    void bubble_sort(itr_begin first, itr_begin last)
    {
        auto first_copy = first;
        auto const length = std::distance(first, last);
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                //std::cout << "Befor if: First : " << *(std::next(first_copy, i)) << "Second:" <<   *(std::next(first_copy, j)) <<std::endl;
                if (*(std::next(first_copy, j)) > *(std::next(first_copy, j+1)))
                {
               //     std::cout << "Inside if \n";
                    const auto value = *(std::next(first_copy, j));
                    *(std::next(first_copy, j)) = *(std::next(first_copy, j+1));
                    *(std::next(first_copy, j+1)) = value;
                }
              //  std::cout << "After if: First : " << *(std::next(first_copy, i)) << "Second:" <<   *(std::next(first_copy, j)) <<std::endl;

            }
        }
    }

} // namespace lib

#endif