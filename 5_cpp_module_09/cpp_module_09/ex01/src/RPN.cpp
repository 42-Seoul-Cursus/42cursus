#include "RPN.hpp"
#include <iostream>
#include <stack>

RPN::RPN(const std::string& input)
: mInput(input)
{
}
RPN::~RPN()
{
}
int RPN::Evaluate(void) const
{
    std::stack<int> st;
    ll res, a, b;

    for (size_t i = 0; i < mInput.length(); i++)
    {
        if (isWhitespace(mInput[i]))
        {
            continue;
        }
        if ('0' <= mInput[i] && mInput[i] <= '9')
        {
            st.push(mInput[i] - '0');
            continue;
        }
        if (st.size() < 2)
        {
            throw std::runtime_error("Error: Invalid input");
        }

        a = st.top(); st.pop();
        b = st.top(); st.pop();
        switch (mInput[i])
        {
            case '+':
                res = b + a;
                break;
            case '-':
                res = b - a;
                break;
            case '*':
                res = b * a;
                break;
            case '/':
                a == 0 ? throw std::runtime_error("Error: Division by zero") : st.push(b / a);
                res = b / a;
                break;
            default:
                throw std::runtime_error("Error: Invalid operator");
        }
        if (res < std::numeric_limits<int>::min() ||res > std::numeric_limits<int>::max())
        {
            throw std::runtime_error("Error: Overflow");
        }
        st.push(res);
    }
    if (st.size() != 1)
    {
        throw std::runtime_error("Error: Invalid input");
    }
    return st.top();
}
bool isWhitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}
