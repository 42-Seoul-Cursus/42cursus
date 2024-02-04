#ifndef SPAN_HPP
#define SPAN_HPP

#include <iosfwd>

class Span
{
private:
	int* mData;
	const unsigned int mMaxStore;
	unsigned int mCnt;
	const Span&	operator=(const Span& rhs);
public:
	Span(unsigned int maxStore);
	~Span();
	Span(const Span& rhs);
	void			AddNumber(int data);
	int				ShortestSpan() const;
	int				LongestSpan() const;
	int&			operator[](const unsigned int idx);
	template <typename T>
	void AddNumbers(typename T::iterator first, typename T::iterator last)
	{
		for (; first != last; ++first)
		{
			if (mCnt == mMaxStore)
			{
				throw "\033[0;33mSpan is full and can't be added more.\033[0m";
			}
			mData[mCnt++] = *first;
		}
	}
};

#endif
