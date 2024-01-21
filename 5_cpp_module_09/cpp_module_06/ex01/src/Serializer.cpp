#include <stdint.h>
#include "Serializer.hpp"

uintptr_t Serializer::Serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::Deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
