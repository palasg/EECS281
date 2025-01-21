/* Type your code here, or load an example. */
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// template <typename T>
// class dummy {
//    private:
//     std::vector<T> dummy{T(), 5};
// };

// Before C++20
//  template<typename T>
//  T maxValue(const T& first, const T& second ){
//      return (first > second) ? first: second;
//  }

// //give constrain
// template<typename T, typename = std::enable_if_t<not std::is_pointer_v<T> >>
// T maxValue(const T& first, const T& second ){
//     return (first > second) ? first: second;
// }

// C++ 20
//  requires clause
//  template<typename T>
//  requires (not std::is_pointer_v<T>)
//  T maxValue(const T& first, const T& second ){
//      return (first > second) ? first: second;
//  }

// template <typename T>
// concept IsPointer = std::is_pointer_v<T>;

// template <typename T>
//     requires(not IsPointer<T>)
// T maxValue(const T& first, const T& second) {
//     return (first > second) ? first : second;
// }

// template <typename T>
//     requires(IsPointer<T>)
// auto maxValue(const T first, const T second) {
//     return maxValue(*first, *second);
// }

// //overload resolution with constrain is more specialized
// template<typename T>
// T maxValue(const T* first, const T* second ){
//     return maxValue(*first, *second);
// }

// square odd numbers

// void IDK() {
//     std::vector<int> values{1, 2, 4, 5, 6, 7, 8, 9, 11};
//     std::vector<int> odd_numbers{};
//     auto isOdd = [](auto t) { return t % 2 != 0; };
//     std::copy_if(std::begin(values), std::end(values),
//                  std::back_inserter(odd_numbers), isOdd);
//     std::transform(std::begin(odd_numbers), std::end(odd_numbers),
//                    std::begin(odd_numbers),
//                    [](const int& value) { return value * value; });

//     for (const auto v : odd_numbers) {
//         std::cout << v << ",";
//     }
//     std::cout << std::endl;
// }

// void viewAndPipeOperator() {
//     std::vector<int> values{1, 2, 4, 5, 6, 7, 8, 9, 11};
//     auto isOdd = [](auto t) { return t % 2 != 0; };
//     auto results = values | std::views::filter(isOdd) |
//                    std::views::transform([](int n) { return n * n; });
//     for (const auto v : results) {
//         std::cout << v << ",";
//     }
//     std::cout << std::endl;
// }

// /// sort algorithms
// template <typename itr_begin, typename = std::_RequireInputIter<itr_begin>>
// void bubble_sort(itr_begin first, itr_begin last) {
//     auto first_copy = first;
//     auto const length = std::distance(first, last);
//     for (int i = 0; i < length; i++) {
//         for (int j = 0; j < length; j++) {
//             std::cout << "Befor if: First : " << *(std::next(first_copy, i))
//                       << "Second:" << *(std::next(first_copy, j)) << std::endl;
//             if (*(std::next(first_copy, j)) > *(std::next(first_copy, j + 1))) {
//                 std::cout << "Inside if \n";
//                 const auto value = *(std::next(first_copy, j));
//                 *(std::next(first_copy, j)) = *(std::next(first_copy, j + 1));
//                 *(std::next(first_copy, j + 1)) = value;
//             }
//             std::cout << "After if: First : " << *(std::next(first_copy, i))
//                       << "Second:" << *(std::next(first_copy, j)) << std::endl;
//         }
//     }
// }

int main() {
std::cout << "Hello main \n";
    return 0;
}
