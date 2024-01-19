#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
private:
	Brain* mBrain;
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat& rhs);
	const WrongCat&	operator=(const WrongCat& rhs);
	void			MakeSound() const;
	void			AddIdea(const std::string& idea);
	void			PrintAllIdeas(void) const;
};

#endif 
