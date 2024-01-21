#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data me = {24, "seunan"};

	uintptr_t serializedPtr = Serializer::Serialize(&me);
	Data* deserializedPtr = Serializer::Deserialize(serializedPtr);
	
	std::cout << "0x" << std::hex << serializedPtr << std::endl;
	std::cout << deserializedPtr << std::endl;
	return 0;
}
