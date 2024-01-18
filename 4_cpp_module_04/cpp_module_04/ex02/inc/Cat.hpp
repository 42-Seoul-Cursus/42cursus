#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain* mBrain;
public:
	Cat();
	~Cat();
	Cat(const Cat& rhs);
	const Cat&	operator=(const Cat& rhs);
	virtual void	makeSound() const;
	void			AddIdea(const std::string& idea);
	void			PrintAllIdeas(void) const;
};

#endif 
