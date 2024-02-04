#include <cmath>
#include "Span.hpp"

Span::Span(unsigned int maxStore)
: mData(new int[maxStore])
, mMaxStore(maxStore)
, mCnt(0) {}
Span::~Span() 
{
	delete[] mData;
}
Span::Span(const Span& rhs)
: mData(new int[rhs.mMaxStore])
, mMaxStore(rhs.mMaxStore) 
, mCnt(rhs.mCnt) 
{
	for (size_t i = 0; i < mMaxStore; i++)
	{
		mData[i] = rhs.mData[i];
	}
}
void Span::AddNumber(int data)
{
	if (mCnt == mMaxStore)
	{
		throw "\033[0;33mSpan is full and can't be added more.\033[0m";
	}
	mData[mCnt++] = data;
}
int Span::ShortestSpan() const
{
	if (mCnt < 2)
	{
		throw "\033[0;33mAt least two integers are required to compare the difference.\033[0m";
	}

	int min = abs(mData[1] - mData[0]);

	for (size_t i = 1; i < mCnt; i++)
	{
		for (size_t j = i + 1; j < mCnt; j++)
		{
			if (min > abs(mData[j] - mData[i]))
			{
				min = abs(mData[j] - mData[i]);
			}
		}
	}
	return min;
}
int Span::LongestSpan() const
{
	if (mCnt < 2)
	{
		throw "\033[0;33mAt least two integers are required to compare the difference.\033[0m";
	}

	int max = abs(mData[1] - mData[0]);

	for (size_t i = 1; i < mCnt; i++)
	{
		for (size_t j = i + 1; j < mCnt; j++)
		{
			if (max < abs(mData[j] - mData[i]))
			{
				max = abs(mData[j] - mData[i]);
			}
		}
	}
	return max;
}
int& Span::operator[](const unsigned int idx)
{
	if (idx >= mMaxStore)
	{
		throw "\033[0;31mOut of range\033[0m";
	}
	return mData[idx];
}
