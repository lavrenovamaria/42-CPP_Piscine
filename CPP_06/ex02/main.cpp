#include "Base.hpp"
#include <iostream>

/*
Цель ex02 — создать структуру наследования
и выявить ее тип после преобразования.
Во-первых, общий процесс проверки типов сильно
отличается от используемого здесь метода,
но для идентификации объектов с полиморфизмом
в структуре наследования можно использовать
dynamic_cast<T>.
*/
Base	*generate(void){
	srand(time(NULL));
	switch (rand() % 3){
		case 0:
			std::cout << "Это мы создали [A] " << std::endl;;
			return new A();
		case 1:
			std::cout << "Это мы создали [B] " << std::endl;;
			return new B();
		case 2:
			std::cout << "Это мы создали [C] " << std::endl;;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p){
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Nothing happened meh";
}

void identify(Base &base) {
	try {
		(void)dynamic_cast<A&>(base);
		std::cout << "A" << std::endl;
	} catch (const std::exception &e) {}
	try {
		(void)dynamic_cast<B&>(base);
		std::cout << "B" << std::endl;
	} catch (const std::exception &e) {}
	try {
		(void)dynamic_cast<C&>(base);
		std::cout << "C" << std::endl;
	} catch (const std::exception &e) {}
}

int main()
{
	Base* obj = generate();
	std::cout << "Ищем по пойнтеру: " << std::endl;
	identify(obj);
	std::cout << "Ищем по ссылке: " << std::endl;
	identify(*obj);
	delete obj;
}
