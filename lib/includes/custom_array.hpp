#ifndef CUSTOME_ARRAY_HPP
#define CUSTOME_ARRAY_HPP

#include <stdexcept>
#include <cassert>
#include <utility>
#include <cstdint>

#include "custom_iterator.hpp"

namespace lib
{
    template <typename T>
    class Array
    {
    private:
        T *m_data = nullptr;
        std::int32_t m_size{0};
        std::int32_t m_capacity{0};
        inline void DeepCopy(const Array &other)
        {
            this->m_data = new T[other.m_capacity];
            this->m_size = other.m_size;
            this->m_capacity = other.m_capacity;
            for (std::int32_t i = 0; i < other.m_size; i++)
            {
                m_data[i] = other.m_data[i];
            }
        }
        inline void Swap(Array &other)
        {
            std::swap(m_data, other.m_data);
            std::swap(m_size, other.m_size);
            std::swap(m_capacity, other.m_capacity);
        }

    public:
        Array() : m_data(nullptr) {}
        Array(const std::int32_t n, const T &value = T()) : m_data(new T[n]), m_size(n), m_capacity(n) {
            for (int32_t i = 0; i < n; i++)
            {
                m_data[i] = value;
            }
            
        }
        ~Array()
        {
            delete[] m_data;
            m_data = nullptr;
        }
        T *Get() { return m_data; }
        
        T &operator[](std::int32_t n)
        {
            if (n < m_size)
            {
                return *(m_data + n);
            }
            else
            {
                throw std::runtime_error{"Invalid index provided \n"};
            }
        }
        const T &operator[](std::int32_t n) const
        {
            if (n < m_size)
            {
                return *(m_data + n);
            }
            else
            {
                throw std::runtime_error{"Invalid index provided \n"};
            }
        }
        std::int32_t Size() const { return m_size; }
        std::int32_t Capacity() const { return m_capacity; }

        // copy constructor
        Array(const Array &other)
        {
            if (other.m_data != nullptr)
            {
                DeepCopy(other);
            }
        }
        // assignment operator
        Array &operator=(const Array &other)
        {
            if (this == &other)
            {
                return *this;
            }
            delete[] m_data;   // deleting nullptr would not hurt you
            Array temp(other); // copy the new data in a temporary variable. So if it fails while allocation the original data
                               // would not lost
            // swap temp and original
            Swap(temp); // swap does not throw exception. Hence copy swap scheme guarantee strong exception safety.
            return *this;
        }

        bool Insert(const int pos, const T &value)
        { // pos >= 0 && <= length-1

            assert(pos < m_size && pos > -1 && "pos should be in between size of the array");

            if (m_capacity < m_size)
            {
                auto old_value = m_data[pos];
                auto new_value = value;
                for (std::int32_t i = pos; i < m_size + 1; i++)
                {
                    old_value = m_data[i];
                    m_data[i] = new_value;
                    new_value = old_value;
                }
            }
            else
            {
                auto new_buffer = new T[m_capacity * 2];
                m_capacity = m_capacity * 2;
                for (int32_t i = 0; i < m_size + 1; i++)
                {
                    if (i < pos)
                    {
                        new_buffer[i] = m_data[i];
                    }
                    else if (i == pos)
                    {
                        new_buffer[i] = value;
                    }
                    else
                    {
                        new_buffer[i] = m_data[i - 1];
                    }
                }
                m_size= m_size+1;
                delete [] m_data;
                m_data = new_buffer;
            }

            return false;
        }
        custom_iterator<T> begin(){return custom_iterator<T>{m_data};}
        const custom_iterator<T> begin()const{return custom_iterator<T>{m_data};}

        custom_iterator<T> end(){return custom_iterator<T>{m_data+m_size};}

    };

} // namespace lib

#endif