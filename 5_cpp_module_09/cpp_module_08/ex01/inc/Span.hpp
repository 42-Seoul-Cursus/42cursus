#ifndef SPAN_HPP
#define SPAN_HPP

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
	void	AddNumber(int data);
	// int		ShortestSpan() const;
	// int		LongestSpan() const;
};

#endif
