#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

typedef unsigned short date_t;
typedef struct Date Date;

class BitcoinExchange
{
private:
    const std::string mInputFile;
    const BitcoinExchange& operator=(const BitcoinExchange& rhs);
    void parseDb(std::map<std::string, double>& db);
    bool parseLine(std::map<std::string, double>& db, std::string& line);
    void processInput(std::map<std::string, double>& db);
    void processLine(std::map<std::string, double>& db, std::string& line);
    bool isValidDate(const Date& date);
    std::string getDateStr(const Date& date);

public:
    BitcoinExchange(const std::string& inputFile = "input.txt");
    BitcoinExchange(const BitcoinExchange& rhs);
    ~BitcoinExchange();
    void Exchange(void);
};

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

struct Date
{
    date_t year;
    date_t month;
    date_t day;
};

#endif
