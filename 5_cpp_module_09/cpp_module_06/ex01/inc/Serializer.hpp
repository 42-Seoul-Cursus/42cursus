#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

struct Data;

class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& rhs);
	const Serializer& operator=(const Serializer&);
public:
	static uintptr_t	Serialize(Data* ptr);
	static Data*		Deserialize(uintptr_t raw);
};

#endif
