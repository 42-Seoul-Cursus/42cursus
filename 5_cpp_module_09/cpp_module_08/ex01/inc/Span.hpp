#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <exception>

class SpanFullException : public std::exception
{
public:
    const char* what() const _NOEXCEPT
    {
        return "\033[33mSpan is full and can't be added more.\033[0m";
    }
};

class InsufficientNumbersException : public std::exception
{
public:
    const char* what() const _NOEXCEPT
    {
        return "\033[33mSAt least two integers are required to compare the difference.\033[0m";
    }
};

class Span
{
private:
    int* mpData;
    size_t mMaxStore;
    size_t mCur;
    bool hasSufficientNumbers() const;

public:
    Span(size_t maxStore);
    Span(const Span& rhs);
    ~Span();
    const Span& operator=(const Span& rhs);
    void AddNumber(int data);
    int ShortestSpan() const;
    int LongestSpan() const;
    int& operator[](const size_t idx);
    template <typename T>
    void AddNumbers(typename T::iterator start, typename T::iterator end)
    {
        for (; start != end; ++start)
        {
            AddNumber(*start);
        }
    }
};

#endif
