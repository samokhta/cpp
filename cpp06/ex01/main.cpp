#include "Serializer.hpp"

int	main(int ac, char **av)
{
	Data		test;
	Data		*pTest;
	uintptr_t	sTest;

	if (ac != 2)
		return 1;
	test.content = av[1];
	sTest = Serializer::serialize(&test);
	pTest = Serializer::deserialize(sTest);
	std::cout << "original content: " << test.content << std::endl;
	std::cout << "serialized pointer: " << sTest << std::endl;
	std::cout << "deserialized content: " << pTest->content << std::endl;

	return (0);
}