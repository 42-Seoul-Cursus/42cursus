#include "Span.hpp"
#include <algorithm>

Span::Span(size_t maxStore)
: mpData(new int[maxStore])
, mMaxStore(maxStore)
, mCur(0)
{
}
Span::Span(const Span& rhs)
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
const Span& Span::operator=(const Span& rhs)
{
    if (this != &rhs)
    {
        if (mMaxStore != rhs.mMaxStore)
        {
            delete[] mpData;
            mMaxStore = rhs.mMaxStore;
            mpData = new int[mMaxStore];
        }
        for (mCur = 0; mCur < rhs.mCur; mCur++)
        {
            mpData[mCur] = rhs.mpData[mCur];
        }
    }
    return *this;
}
void Span::AddNumber(int data)
{
    if (mCur == mMaxStore)
    {
        throw SpanFullException();
    }
    mpData[mCur++] = data;
}
int Span::ShortestSpan() const
{
    if (!hasSufficientNumbers())
    {
        throw InsufficientNumbersException();
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
    if (!hasSufficientNumbers())
    {
        throw InsufficientNumbersException();
    }

    Span tmp(*this);
    std::sort(tmp.mpData, tmp.mpData + tmp.mCur);

    return tmp[mCur - 1] - tmp[0];
}
int& Span::operator[](const size_t idx)
{
    if (idx >= mMaxStore)
    {
        throw std::out_of_range("\033[0;31mIndex exceeds allowed boundaries.\033[0m");
    }
    return mpData[idx];
}
bool Span::hasSufficientNumbers() const
{
    if (mCur < 2)
    {
        return false;
    }
    return true;
}
