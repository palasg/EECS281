#ifndef CIRCULAR_BUFFER_HPP
#define CIRCULAR_BUFFER_HPP
#include <vector>
#include<cassert>

namespace lib
{

    template <typename T>
    class circularBuffer
    {
    public:
        circularBuffer(const std::size_t capacity);
        ~circularBuffer(){}

    private:
        int head_pos;
        int tail_pos;
        static constexpr  std::size_t m_max_capacity{100};
        std::vector<T> m_buffer(T(),m_max_capacity);
              
    };

    template<typename T>
    circularBuffer<T>::circularBuffer(const std::size_t capacity){

        assert(capacity < m_max_capacity && "buffer max size must be less than 100");
        m_buffer.resize(capacity);
        
    }

} // namespace lib
#endif