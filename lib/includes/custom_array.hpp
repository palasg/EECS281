#ifndef CUSTOME_ARRAY_HPP
#define CUSTOME_ARRAY_HPP
#include<cstddef>
#include<iostream>

namespace lib
{
    template<typename T> 
    class Array
    {
    private:
        T* m_data = nullptr; 
        std::size_t m_size{ 0 };
        std::size_t m_capacity { 0 };

    public:
        Array(): m_data(nullptr){}
        Array(const size_t n, const T& value= T()): m_data(new T[n](value)), m_size(n), m_capacity(n){}
        ~Array(){delete [] m_data;}
        T* Get(){return m_data;}
        T& operator[](size_t n){return *(m_data+n);}
        size_t Size() const {return m_size;}
        size_t Capacity()const{return m_capacity;}

        // copy constructor
        Array(const Array& other){
            if(other.m_data!=nullptr){
                this->m_data = new T[other.m_capacity];       
                this->m_size = other.m_size;
                this->m_capacity = other.m_capacity;
                for (size_t i = 0; i < other.m_size; i++)
                {
                    m_data[i] = other.m_data[i];
                }
            }

        }
    };
    
} // namespace lib



#endif