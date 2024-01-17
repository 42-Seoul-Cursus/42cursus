#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* mBrain;
public:
	Cat();
	~Cat();
	Cat(const Cat& rhs);
	const Cat&	operator=(const Cat& rhs);
	void		makeSound() const;
	void		AddIdea(const std::string& idea);
	void		PrintAllIdeas(void) const;
};

#endif 
