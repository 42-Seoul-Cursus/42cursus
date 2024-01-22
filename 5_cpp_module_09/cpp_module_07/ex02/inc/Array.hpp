#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stddef.h>

template <typename T>
class Array
{
private:
	T* mData;
	size_t mSize;
public:
	Array();
	Array(size_t size);
	~Array();
	Array(const Array& rhs);
	const Array&	operator=(const Array& rhs);
	T&				operator[](const size_t idx) const;
	size_t			size() const;
};

#endif
