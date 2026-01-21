#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <stdint.h>
#include <iostream>

typedef struct Data {
	std::string	content;
}	Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer &operator=(const Serializer& other);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

};

#endif