#include "BitcoinExchange.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

const Date BITCOIN_CREATION_DAY = {2009, 1, 2};
const date_t MIN_MONTH = 1;
const date_t MAX_MONTH = 12;
const std::string DB_HEADER = "date,exchange_rate";
const std::string INPUT_HEADER = "date | value";

BitcoinExchange::BitcoinExchange(const std::string& inputFile)
: mInputFile(inputFile)
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
: mInputFile(rhs.mInputFile)
{
}
BitcoinExchange::~BitcoinExchange()
{
}
void BitcoinExchange::Exchange(void)
{
    std::map<std::string, double> db;

    try
    {
        parseDb(db);
        processInput(db);
    }
    catch(const std::exception& e)
    {
        throw e;
    }
}
void BitcoinExchange::parseDb(std::map<std::string, double>& db)
{
    const std::string filename = "data.csv";
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error(aec::fg::RED + "Error: Failed to open the " + filename + " file." + aec::RESET);
    }

    std::string line;
    std::getline(file, line);
    if (line != DB_HEADER)
    {
        throw std::runtime_error(aec::fg::RED + "Error: The format of the " + filename + " file is not correct." + aec::RESET);
    }

    while (!file.eof())
    {
        std::getline(file, line);
        if (line[0] == '\0')
        {
            break;
        }
        if (!parseLine(db, line))
        {
            throw std::runtime_error(aec::fg::RED + "Invalid format" + aec::RESET);
        }
    }
    if (!file.eof())
    {
        throw std::runtime_error(aec::fg::RED + "Invalid format" + aec::RESET);
    }
}
bool BitcoinExchange::parseLine(std::map<std::string, double>& db, std::string& line)
{
    std::istringstream iss(line);
    Date date;
    char dash[2];
    char sep;
    double val;

    iss >> date.year >> dash[0] >> date.month >> dash[1] >> date.day >> sep >> val;
    if (!isValidDate(date))
    {
        return false;
    }
    if (!iss.eof() || sep != ',' || dash[0] != '-' || dash[1] != '-')
    {
        return false;
    }
    const std::string str_date = getDateStr(date);
    db.insert(make_pair(str_date, val));
    return true;
}
void BitcoinExchange::processInput(std::map<std::string, double>& db)
{
    std::ifstream file(mInputFile);

    if (!file.is_open())
    {
        throw std::runtime_error(aec::fg::RED + "Error: Failed to open the " + mInputFile + " file." + aec::RESET);
    }

    std::string line;
    std::getline(file, line);
    if (line != INPUT_HEADER)
    {
        throw std::runtime_error(aec::fg::RED + "Error: The format of the " + mInputFile + " file is not correct." + aec::RESET);
    }
    while (!file.eof())
    {
        std::getline(file, line);
        if (line[0] == '\0')
        {
            continue;
        }
        processLine(db, line);
    }
}
void BitcoinExchange::processLine(std::map<std::string, double>& db, std::string& line)
{
    std::istringstream iss(line);
    Date date;
    char dash[2];
    char sep;
    double val;

    iss >> date.year >> dash[0] >> date.month >> dash[1] >> date.day >> sep >> val;

    if (!isValidDate(date) || !iss.eof() || sep != '|' || dash[0] != '-' || dash[1] != '-')
    {
        std::cout << aec::fg::RED << "Error: bad input => " << line << aec::RESET << '\n';
    }
    else if (val < 0)
    {
        std::cout << aec::fg::RED << "Error: not a positive number." << aec::RESET << '\n';
    }
    else if (val > 1000)
    {
        std::cout << aec::fg::RED << "Error: too large a number." << aec::RESET << '\n';
    }
    else
    {
        const std::string str_date = getDateStr(date);
        std::map<std::string, double>::iterator it = db.upper_bound(str_date);
        it != db.begin() ? --it : it;
        std::cout << aec::fg::GREEN << str_date << " => " << val << " = " << val * it->second << aec::RESET << '\n';
    }
}
std::string BitcoinExchange::getDateStr(const Date& date)
{
    const std::string month = date.month < 10 ? "0" + std::to_string(date.month) : std::to_string(date.month);
    const std::string day = date.day < 10 ? "0" + std::to_string(date.day) : std::to_string(date.day);

    return std::to_string(date.year) + '-' + month + '-' + day;
}
bool BitcoinExchange::isValidDate(const Date& date)
{
    time_t now = time(0);
    tm* cur = localtime(&now);
    date_t current_year = cur->tm_year + 1900;

    if (date.year > current_year || date.year < BITCOIN_CREATION_DAY.year)
    {
        return false;
    }
    if (date.month > MAX_MONTH || date.month < MIN_MONTH)
    {
        return false;
    }

    bool bIsLeapYear = false;
    if (date.year % 400 == 0 || (date.year % 4 == 0 && date.year % 100 != 0))
    {
        bIsLeapYear = true;
    }

    date_t days[MAX_MONTH] = {31, bIsLeapYear ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date.day > days[date.month - 1] || date.day < 1)
    {
        return false;
    }
    if (date.year == BITCOIN_CREATION_DAY.year && date.month == BITCOIN_CREATION_DAY.month && date.day < BITCOIN_CREATION_DAY.day)
    {
        return false;
    }
    return true;
}
