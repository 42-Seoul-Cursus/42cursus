#include <exception>
#include "Span.hpp"

Span::Span(unsigned int maxStore)
: mData(new int[maxStore])
, mMaxStore(maxStore)
, mCnt(0) {}
Span::~Span() {}
Span::Span(const Span& rhs)
: mData(new int[rhs.mMaxStore])
, mMaxStore(rhs.mMaxStore) 
, mCnt(rhs.mCnt) {}
void Span::AddNumber(int data)
{
	if (mCnt == mMaxStore)
	{
		throw std::exception();
	}
	mData[mCnt++] = data;
}
// int Span::ShortestSpan() const;
// int Span::LongestSpan() const;
