#include <algorithm>
#include "Span.hpp"

Span::Span(size_t maxStore)
: mpData(new int[maxStore])
, mMaxStore(maxStore)
, mCur(0) {}
Span::Span(const Span &rhs)
: mpData(new int[rhs.mMaxStore])
, mMaxStore(rhs.mMaxStore) 
, mCur(0)
{
	for (; mCur < mMaxStore; mCur++)
	{
		mpData[mCur] = rhs.mpData[mCur];
	}
}
Span::~Span() 
{
	delete[] mpData;
}
void Span::AddNumber(int data)
{
	if (mCur == mMaxStore)
	{
		throw "\033[0;33mSpan is full and can't be added more.\033[0m";
	}
	mpData[mCur++] = data;
}
int Span::ShortestSpan() const
{
	if (mCur < 1)
	{
		throw "\033[0;33mAt least two integers are required to compare the difference.\033[0m";
	}

	Span tmp(*this);
	std::sort(tmp.mpData, tmp.mpData + tmp.mCur);

	int min = tmp[1] - tmp[0];
	for (size_t i = 1; i < mCur; i++)
	{
		if (min > tmp[i] - tmp[i - 1])
		{
			min = tmp[i] - tmp[i - 1];
		}
	}
	return min;
}
int Span::LongestSpan() const
{
	if (mCur < 1)
	{
		throw "\033[0;33mAt least two integers are required to compare the difference.\033[0m";
	}

	Span tmp(*this);
	std::sort(tmp.mpData, tmp.mpData + tmp.mCur);

	return tmp[mCur - 1] - tmp[0];
}
int& Span::operator[](const size_t idx)
{
	if (idx >= mMaxStore)
	{
		throw "\033[0;31mOut of range\033[0m";
	}
	return mpData[idx];
}
