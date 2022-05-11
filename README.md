# 42-CPP-Piscines

<details>
  <summary>CPP_00-ex00 </summary>

###
Можно юзать системную штуку (char)toupper

```
#include <iostream>

int main()
{
	std::cout << "Hello World!" << std::endl;
	return 0;
}
```
Чтобы читать или писать в стандартный поток ввода/вывода необходимо включить <iostream>
Любая переменная или объект, существующий в стандартной библиотеке C++, включается в стандартное пространство имен std.
Чтобы использовать стандартный объект вывода, вам нужно написать std::cout, чтобы присоединить [пространство имен](https://docs.microsoft.com/ru-ru/cpp/cpp/namespaces-cpp?view=msvc-170)
Пространство имен означает принадлежность определенному объекту или функции. Когда объект объявлен в a() и b(), это означает, что он может использоваться только с другим префиксом.\
abc a::abc b::abc
```
int doSomething(int x, int y)
{
	return x + y;
}
```
```
int doSomething(int x, int y)
{
	return x - y;
}
```
```
#include <iostream>
int main()
{
	std::cout << doSomething(4, 3);
	return 0;
}
```
Если эти два параметра включены в одну и ту же программу, что и в примере, возникает конфликт имен, поскольку функция с тем же именем и параметром находится в той же области.
```
namespace Foo
{
	int doSomething(int x, int y)
	{
		return x + y;
	}
}
```
```
namespace Goo
{
	int doSomething(int x, int y)
	{
		return x - y;
	}
}
```
```
#include <iostream>

int main()
{
	std::cout << Foo::doSomething(4, 3); << '\n'
	std::cout << Goo::doSomething(4, 3); << endl
	return 0;
}
```
Если над проектом работают два разработчика и они оба решили назвать свою функцию doSomething, то при сборке будет больно. Поэтому можно использовать пространство имён. Для этого используем namespace Foo и namespace Goo. Таким образом обе функции doSomething не будут ничего знать друг о друге и всё скомпилируется успешно.
Оператор разрешения области действия (::) необходим для поиска идентификаторов в каждом пространстве имен.
Чтобы использовать этот оператор, добавьте к имени идентификатора префикс пространства имен, которое будет использоваться.

</details>

<details>
  <summary>CPP_04-ex00 </summary>

```c
#include <iostream>
using namespace std;//просто чтобы не писать "std::"" каждый раз

class Animal {
	public:
	void eat() {
		cout << "Я как и любое другое животное могу кушоц!" << endl;
	}

	void sleep() {
		cout << "Как и любое другое животное могу спац!" << endl;
	}
};

class Dog : public Animal {

	public:
	void bark() {
		cout << "Я собакен и я делаю гав-гав!" << endl;
	}
};

// int main() {
// 	Dog dog;

// 	dog.eat();
// 	dog.sleep();
// 	dog.bark();
// 	return 0;
// }

//---------------------пример из видео-------------------------//
class Gun{
	public:
		virtual void Shoot()//virtual мы пишем чтобы была возможность переопределить метод в наследнике(в Uzi)
		{
			cout << "Bang!" << endl;
		}
};

class Uzi: public Gun{
	public:
		void Shoot() //override пишется здесь по-хорошему после скобочек, но это для С++11 стандарта
		{
			cout << "Bang! Bang! Bang!" << endl;
		}
};

int main() {
	Gun gun;//создали объект класса Gun
	Uzi uzi;//объект класса Uzi, который наследник класса Gun

	Gun *weapon = &uzi; //1-создали указатель на Gun, который ссылается на uzi
	//Gun *weapon = &gun; //2-создали указатель на Gun, который ссылается на gun

	//такой указатель может ссылаться на свой собственный тип
	//на объект такого же класса
	//либо ссылаться на любой другой класс, который унаследован от него

	weapon->Shoot();
	//если 1, то будет Bang! Bang! Bang!
	//если 2, то будет Bang!
	return 0;
}
```

</details>

<details>
  <summary>Простейший пример инкапсуляции(get, set) </summary>

```c
#include <iostream>
using namespace std;//просто чтобы не писать "std::"" каждый раз

class Point{
	private:
		int _x;
		int _y;
		int _z;
	public:
		int getX(){
			return _x;
		}
		void setX(int valueX){
			_x = valueX;
		}
	void print()
	{
		cout << "X = " << _x << endl;
		cout << "Y = " << _y << endl;
	}
};

int main()
{
	Point a;
	a.setX(5);
	a.print();

	return 0;
}
```
</details>

<details>
  <summary>Template это формочка для кексика, но не сам кексик, мы отдаём компилятору формочку, а он нам печёт кексики </summary>

```c
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

//template< разделенный запятыми список параметров >
//Ключевое слово typename задает так называемый параметр,
//являющийся типом, или, для краткости — параметр типа(типовой параметр)
//template <typename T> = template <сlass T>
template < typename T >
T max(T a, T b){
	return b < a ? a : b;
	//Если b < а, возвращаем а, в противном случае b
}

template < typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template < typename T >
T min(T a, T b){
	return b > a ? a : b;
}

#endif

//Процесс замены параметров шаблона конкретными
//типами называется инстанцированием шаблона
//(instantiation). Его результатом является экземпляр
//(instance) шаблона
```

</details>

<details>
  <summary>CPP_06-ex01 </summary>

```c
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
```

</details>
