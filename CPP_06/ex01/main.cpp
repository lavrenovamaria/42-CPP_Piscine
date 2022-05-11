#include <iostream>

/*reinterpret_cast<type>(expr)
type задает результирующий тип приведения expr выражение,
которое приводится к новому типу преобразует один тип в совершенно другой
например, он может преобразовать указатель на целое число в целое число
а целое число в указатель
самый тупенький - заставляет компилятор принимать ситуации, которые static_cast
обычно не допускает
*/

/*
В этом задании требуется преобразовать указатель на Data,
который является произвольным классом или структурой, определяемой пользователем,
в uintptr_t, а затем преобразовать uintptr_t обратно в указатель на Data.
В этом процессе необходимо убедиться,
что нет пропущенных данных, и данные должны быть сохранены нетронутыми
*/

/*
uintptr_t — это псевдоним беззнакового числового типа.
В моем случае uintptr_t — это unsigned long.
Псевдоним для числового типа со знаком — intptr_t,
а uintptr_t и intptr_t идентичны в том смысле,
что они используются для хранения адреса, на который
ссылается указатель, в виде числа.
В некоторых системах можно увидеть, что intptr_t
может быть назначен как signed, так и unsigned,
тогда как uintptr_t может назначить только unsigned
и для signed требуется отдельное преобразование типа.
По этой причине, начиная с языка C, рекомендуется
использовать intptr_t, а не uintptr_t для гибкости программы.
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
