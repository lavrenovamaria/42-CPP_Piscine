#include <iostream>

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

Data* deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}

uintptr_t serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

int main(){
	Data data;
	Data *newData = NULL;
	data.data = 42;
	data.string = "В голове моей опилки";

	std::cout << "newData: " << newData << "\n";
	std::cout << "data string: " << data.string << std::endl;
	std::cout << "data int: " << data.data << std::endl;

	uintptr_t ptr;
	ptr = serialize(&data);
	newData = deserialize(ptr);

	std::cout << "newData: " << newData << "\n";
	std::cout << "data string: " << data.string << std::endl;
	std::cout << "data int: " << data.data << std::endl;

	return 0;
}
