#ifndef CUSTOM_ITERATOR_HPP
#define CUSTOM_ITERATOR_HPP

#include <cstddef>
#include <iterator>

namespace lib {

template <typename T> class custom_iterator {
private:
  T *m_ptr;

public:
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using reference = T &;
  using pointer = T *;
  using iterator_catagory = std::random_access_iterator_tag;

  custom_iterator(T *ptr) : m_ptr(ptr) {}
  ~custom_iterator() {
    m_ptr = nullptr;
  } // it soes not own so resposibility to release is not with this class
  custom_iterator(const custom_iterator &other) : m_ptr(other.m_ptr) {}
  custom_iterator &operator=(const custom_iterator &other) {
    m_ptr = other.m_ptr;
  }
  custom_iterator &operator+=(const difference_type n) {
    m_ptr += n;
    return *this;
  }
  custom_iterator &operator++() {
    *this += 1;
    return *this;
  }
  custom_iterator operator++(int) {
    auto temp = m_ptr;
    *this += 1;
    return temp;
  }

  custom_iterator &operator-=(const difference_type n) {
    m_ptr -= n;
    return *this;
  }
  custom_iterator &operator--() {
    *this -= 1;
    return *this;
  }
  custom_iterator operator--(int) {
    auto temp = m_ptr;
    *this -= 1;
    return temp;
  }
  reference operator*() { return *m_ptr; }
  pointer operator->() { return m_ptr; }
  reference operator[](const difference_type n) { return *(m_ptr + n); }
  value_type operator[](const difference_type n) const { return *(m_ptr + n); }
  friend bool operator==(const custom_iterator &first,
                         const custom_iterator &second) {
    return first.m_ptr == second.m_ptr;
  }
  friend bool operator!=(const custom_iterator &first,
                         const custom_iterator &second) {
    return not(first.m_ptr == second.m_ptr);
  }
  
};

} // namespace lib

#endif