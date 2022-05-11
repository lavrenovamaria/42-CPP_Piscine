#include <iostream>
#include <assert.h>

/*
В этом задании требуется преобразовать указатель на Data,
который является произвольным классом или структурой, определяемой пользователем,
в uintptr_t, а затем преобразовать uintptr_t обратно в указатель на Data.
В этом процессе необходимо убедиться,
что нет пропущенных данных, и данные должны быть сохранены нетронутыми
*/

struct Data
{
	int data;
	std::string string;
};

uintptr_t serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}


int main(){
	Data data;
	Data *oldData = NULL;//or NULL
	oldData = &data;
	Data *newData;
	data.data = 42;
	data.string = "В голове моей опилки";
	std::cout << "oldData adress: " << oldData << "\n";
	std::cout << "old data string: " << data.string << std::endl;
	std::cout << "old data int: " << data.data << std::endl;

	uintptr_t ptrDataHolder;
	ptrDataHolder = serialize(oldData);
	newData = deserialize(serialize(deserialize(serialize(oldData))));
	assert (oldData == newData);

	std::cout << "newData adress: " << newData << "\n";
	std::cout << "data string: " << data.string << std::endl;
	std::cout << "data int: " << data.data << std::endl;

	return 0;
}
