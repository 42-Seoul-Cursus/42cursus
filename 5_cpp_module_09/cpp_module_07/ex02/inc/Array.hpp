#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template <typename T>
class Array
{
private:
    T* mData;
    size_t mSize;

public:
    Array(size_t size = 0);
    ~Array();
    Array(const Array& rhs);
    const Array& operator=(const Array& rhs);
    T& operator[](const size_t idx);
    size_t size() const;
};

#endif
