#ifndef STACKS_QUEUES_HPP
#define STACKS_QUEUES_HPP
#include <optional>
#include<cassert>
namespace lib
{
    // stacks implementation using array

    template <typename eleT>
    class stack
    {
    public:
        stack(const int stack_size = 0)
        {
            assert(stack_size >=0 && "stack size cannot be negative");
            m_capacity = stack_size > 0 ? stack_size : default_size;
            m_data =  new eleT[m_capacity] ;
            m_top = m_data;
        }
        ~stack(){
            delete [] m_data;
            m_top = nullptr;
        }
        std::optional<eleT> top()
        {
            if (m_top != m_data)
            {
                return {*(m_top - 1)};
            }
            return std::nullopt;
        }
        void pop()
        {
            m_top--;
            if (m_top == m_data)
            {
                m_top = nullptr;
                m_data = nullptr;
            }
            
        }
        void push(const eleT &value)
        {
            if ((m_top - m_top) >= m_capacity)
            {
                // new allocation with copy
                const auto new_capacity = m_capacity*2;
                eleT* new_array = new eleT[new_capacity];
                for (int i = 0; i < m_capacity-1; i++)
                {
                    new_array[i] = m_data[i];
                }

                m_top = (new_array+ m_capacity);
                m_capacity = new_capacity;
                std::swap(m_data, new_array);
                delete [] new_array;
                
            }
            else
            {
                *m_top = value;
                ++m_top;
            }
        }

    private:
        int m_capacity{0};
        eleT *m_data = nullptr;
        eleT *m_top = nullptr;
        static constexpr std::size_t default_size{10};
    };

} // namespace lib

#endif