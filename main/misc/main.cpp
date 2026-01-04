
#include"print_utils.hpp"
#include"custom_iterator.hpp"

struct Useless
{
    int m_int{};
    double m_double{};
};


#include<vector>
int main(){
    std::vector v{11,22,33};
    lib::printVector(v);
    lib::custom_iterator itr (v.data());
    std::cout << *(++(++itr))<<" "<<*(itr++)<<" "<<*(itr)<<std::endl;

    std::vector<Useless> useless_vector{{11,11.11},{22,22.22},{33,33.33}};
    lib::custom_iterator itr2 (useless_vector.data());
    std::cout << (*(++(++itr2))).m_int<<" "<<(*(itr2++)).m_double<<" "<<itr2->m_double<<std::endl;
    std::cout << (*(--(--itr2))).m_int<<" "<<(*(itr2--)).m_double<<" "<<itr2->m_double<<std::endl;
    auto itr3 = itr2++;
    std::cout << std::boolalpha << (itr2 == itr3) << std::endl;

    return 0;
}