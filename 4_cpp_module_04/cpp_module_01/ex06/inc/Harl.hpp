#ifndef HARL_HPP
#define HARL_HPP

#include <string>

enum eLevel
{
	DEBUG = 4,
	INFO = 3,
	WARNING = 2,
	ERROR = 1
};

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	void	complain(std::string level);
};

#endif
