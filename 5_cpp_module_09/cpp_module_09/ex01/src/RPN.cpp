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
size_t RPN::Evaluate(void) const
{
    std::stack<int> stack;

    for (size_t i = 0; i < mInput.length(); i++)
    {
        if (mInput[i] == ' ')
        {
            continue;
        }
        else if (mInput[i] >= '0' && mInput[i] <= '9')
        {
            stack.push(mInput[i] - '0');
        }
        else if (stack.size() >= 2)
        {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();

            switch (mInput[i])
            {
                case '+':
                    stack.push(b + a);
                    break;
                case '-':
                    stack.push(b - a);
                    break;
                case '*':
                    stack.push(b * a);
                    break;
                case '/':
                    stack.push(b / a);
                    break;
                default:
                    throw std::runtime_error("Error: Invalid operator");
            }
        }
        else
        {
            throw std::runtime_error("Error: Invalid input");
        }
    }
    if (!stack.empty())
    {
        return stack.top();
    }
    else
    {
        throw std::runtime_error("Error: Invalid input");
    }
}
