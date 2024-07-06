#include "BitcoinExchange.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

const Date BITCOIN_CREATION_DAY = {2009, 1, 2};
const date_t MIN_MONTH = 1;
const date_t MAX_MONTH = 12;
const std::string DATA_HEADER = "date,exchange_rate";
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
    std::map<std::string, double> data_db;
    std::map<std::string, double> input_db;

    parse_file(&data_db, "data.csv", DATA_HEADER, ',');
    parse_file(&input_db, mInputFile, INPUT_HEADER, '|');
}
void BitcoinExchange::parse_file(std::map<std::string, double>* db, const std::string& filename, const std::string& header, char delimiter)
{
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open())
    {
        throw std::runtime_error(aec::fg::RED + "Error: Failed to open the " + filename + " file." + aec::RESET);
    }
    std::getline(file, line);
    if (line != header)
    {
        throw std::runtime_error(aec::fg::RED + "Error: The format of the " + filename + " file is not correct." + aec::RESET);
    }

    while (!file.eof())
    {
        std::getline(file, line);
        // std::cout << line << '\n';
        if (line[0] == '\0')
        {
            break;
        }
        if (!parse_line(db, line, delimiter))
        {
            throw std::runtime_error(aec::fg::RED + "Invalid format" + aec::RESET);
        }
    }
    if (!file.eof())
    {
        throw std::runtime_error(aec::fg::RED + "Invalid format" + aec::RESET);
    }
}
bool BitcoinExchange::parse_line(std::map<std::string, double>* db, std::string& line, char delimiter)
{
    std::stringstream iss(line);
    Date date;
    char dash[2];
    char sep;
    double val;

    iss >> date.year >> dash[0] >> date.month >> dash[1] >> date.day >> sep >> val;
    std::cout << date.year << dash[0] << date.month << dash[1] << date.day << sep << val << '\n';
    if (!isValidDate(date))
    {
        return false;
    }
    if (!iss.eof() || sep != delimiter || dash[0] != '-' || dash[1] != '-')
    {
        return false;
    }
    std::string str_date = std::to_string(date.year) + dash[0] + std::to_string(date.month) + dash[1] + std::to_string(date.day);
    db->insert(make_pair(str_date, val));
    return true;
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
