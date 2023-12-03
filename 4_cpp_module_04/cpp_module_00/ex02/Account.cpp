#include <iostream>
#include <ctime>
#include "Account.hpp"

static int	getNbAccounts( void )
{

}
static int	getTotalAmount( void )
{

}
static int	getNbDeposits( void )
{

}
static int	getNbWithdrawals( void )
{

}
static void	displayAccountsInfos( void )
{

}

Account::Account(int initial_deposit)
{
	(void)initial_deposit;
}
Account::~Account(void)
{

}

void	Account::makeDeposit( int deposit )
{

}
bool	Account::makeWithdrawal( int withdrawal )
{

}
int		Account::checkAmount( void ) const
{

}
void	Account::displayStatus( void ) const
{

}
static void	_displayTimestamp( void )
{
	 // 현재 시간을 얻기
    std::time_t currentTime = std::time(nullptr);

    // std::tm 구조체를 사용하여 시간을 지역 시간으로 변환
    std::tm *localTime = std::localtime(&currentTime);

    // 현재 시간 출력
    std::cout << "현재 시간: " << (localTime->tm_year + 1900) << '-'
              << (localTime->tm_mon + 1) << '-'
              << localTime->tm_mday << ' '
              << localTime->tm_hour << ':'
              << localTime->tm_min << ':'
              << localTime->tm_sec << std::endl;
}
