#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
private:
	std::vector<int> mData;
	const size_t mMaxStore;
	const Span &operator=(const Span &rhs);

public:
	Span(size_t maxStore);
	~Span();
	Span(const Span &rhs);
	void AddNumber(int data);
	int ShortestSpan() const;
	int LongestSpan() const;
	int &operator[](const size_t idx);
	template <typename T>
	void AddNumbers(typename T::iterator first, typename T::iterator last)
	{
		for (; first != last; ++first)
		{
			if (mData.size() == mMaxStore)
			{
				throw "\033[0;33mSpan is full and can't be added more.\033[0m";
			}
			mData.push_back(*first);
		}
	}
};

#endif
