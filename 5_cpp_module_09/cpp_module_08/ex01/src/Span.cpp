#include <cmath>
#include "Span.hpp"

Span::Span(size_t maxStore)
	: mData(), mMaxStore(maxStore) {}
Span::~Span() {}
Span::Span(const Span &rhs)
	: mData(rhs.mData), mMaxStore(rhs.mMaxStore) {}
void Span::AddNumber(int data)
{
	if (mData.size() == mMaxStore)
	{
		throw "\033[0;33mSpan is full and can't be added more.\033[0m";
	}
	mData.push_back(data);
}
int Span::ShortestSpan() const
{
	if (mData.size() < 2)
	{
		throw "\033[0;33mAt least two integers are required to compare the difference.\033[0m";
	}

	std::vector<int> tmp(mData);
	std::sort(tmp.begin(), tmp.end());

	int min = tmp[1] - tmp[0];
	for (std::vector<int>::iterator it = tmp.begin(); it + 1 != tmp.end(); ++it)
	{
		if (min > *(it + 1) - *it)
		{
			min = *(it + 1) - *it;
		}
	}
	return min;
}
int Span::LongestSpan() const
{
	if (mData.size() < 2)
	{
		throw "\033[0;33mAt least two integers are required to compare the difference.\033[0m";
	}

	std::vector<int> tmp(mData);
	std::sort(tmp.begin(), tmp.end());

	return *(tmp.rbegin()) - *(tmp.begin());
}
int& Span::operator[](const size_t idx)
{
	if (idx >= mMaxStore)
	{
		throw "\033[0;31mOut of range\033[0m";
	}
	return mData[idx];
}
