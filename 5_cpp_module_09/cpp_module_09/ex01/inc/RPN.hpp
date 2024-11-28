#ifndef RPN_HPP
#define RPN_HPP

#define ll long long

#include <string>

class RPN
{
private:
    const std::string& mInput;
    RPN(const RPN& rhs);
    RPN& operator=(const RPN& rhs);

public:
    RPN(const std::string& input);
    ~RPN();
    int Evaluate(void) const;
};

bool isWhitespace(char c);

namespace aec
{
    namespace fg
    {
        const std::string BLACK = "\033[90m";
        const std::string RED = "\033[91m";
        const std::string GREEN = "\033[92m";
        const std::string YELLOW = "\033[93m";
        const std::string BLUE = "\033[94m";
        const std::string MAGENTA = "\033[95m";
        const std::string CYAN = "\033[96m";
        const std::string WHITE = "\033[97m";
        const std::string DEFAULT = "\033[39m";
    }  // namespace fg

    namespace bg
    {
        const std::string BLACK = "\033[100m";
        const std::string RED = "\033[101m";
        const std::string GREEN = "\033[102m";
        const std::string YELLOW = "\033[103m";
        const std::string BLUE = "\033[104m";
        const std::string MAGENTA = "\033[105m";
        const std::string CYAN = "\033[106m";
        const std::string WHITE = "\033[107m";
        const std::string DEFAULT = "\033[49m";
    }  // namespace bg

    namespace st
    {
        const std::string DEFAULT = "\033[0m";
        const std::string BOLD = "\033[1m";
        const std::string ITALIC = "\033[3m";
        const std::string UNDERLINE = "\033[4m";
        const std::string REVERSE = "\033[7m";
        const std::string STRIKETHROUGH = "\033[9m";
    }  // namespace st

    const std::string RESET = "\033[0m";
}  // namespace aec

#endif
