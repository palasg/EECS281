#ifndef STACKS_QUEUES_HPP
#define STACKS_QUEUES_HPP
#include <optional>
#include <cassert>
namespace lib
{
    // stacks implementation using array

    template <typename eleT>
    class stack
    {
    public:
        stack(const int stack_size = 0)
        {
            assert(stack_size >= 0 && "stack size cannot be negative");
            m_capacity = stack_size > 0 ? stack_size : default_size;
            m_data = new eleT[m_capacity];
            m_top = m_data;
        }
        ~stack()
        {
            delete[] m_data;
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
                const auto new_capacity = m_capacity * 2;
                eleT *new_array = new eleT[new_capacity];
                for (int i = 0; i < m_capacity - 1; i++)
                {
                    new_array[i] = m_data[i];
                }

                m_top = (new_array + m_capacity);
                m_capacity = new_capacity;
                std::swap(m_data, new_array);
                delete[] new_array;
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

    template <typename T>
    class queue
    {
    public:
        queue(std::size_t length = 10) : m_length(length)
        {
            assert(m_length > 0 && "queue length must be positive");
            m_data = new T[m_length];
            m_back = m_data;
            m_front = m_data;
        }
        ~queue()
        {
            delete[] m_data;
            m_front = nullptr;
            m_back = nullptr;
        }

        void pop()
        {
            ++m_front;
        }
        std::optional<T> front()
        {
            if (m_back != m_front)
            {
                return {*(m_front)};
            }

            return std::nullopt;
        }

        void push(const T &value)
        {
            // for empty array
            *m_back++ = value;
            if (m_back >= (m_data + m_length))
            {
                m_back = m_data;
            }
            if (m_back == m_front)
            {
                T *temp_space = new T[m_length * 2];
                for (size_t i = 0; i < m_length; i++)
                {
                    temp_space[i] = *m_front++;
                    if (m_front == (m_data + m_length)) // if front hit end wrap around
                    {
                        m_front = m_data;
                    }
                }
                std::swap(temp_space, m_data);
                delete[] temp_space;
                m_front = m_data;
                m_back = m_back + m_length;
                m_length = m_length * 2;
            }
        }

    private:
        T *m_data = nullptr;
        T *m_back = nullptr;
        T *m_front = nullptr;
        size_t m_length{0};
        constexpr static size_t initial_length{10};
    };

} // namespace lib

#endif