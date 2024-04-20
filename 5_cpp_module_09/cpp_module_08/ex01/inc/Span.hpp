#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
private:
    int* const mpData;
    const size_t mMaxStore;
    size_t mCur;
    const Span& operator=(const Span& rhs);

public:
    Span(size_t maxStore);
    Span(const Span& rhs);
    ~Span();
    void AddNumber(int data);
    int ShortestSpan() const;
    int LongestSpan() const;
    int& operator[](const size_t idx);
    template <typename T>
    void AddNumbers(typename T::iterator start, typename T::iterator end)
    {
        for (; start != end; ++start)
        {
            if (mCur == mMaxStore)
            {
                throw "\033[0;33mSpan is full and can't be added more.\033[0m";
            }
            mpData[mCur++] = *start;
        }
    }
};

#endif
