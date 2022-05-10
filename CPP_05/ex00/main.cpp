#include  <exception>
#include  <iostream>

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat p1("Mister Kek", 1);
		Bureaucrat p2("Mister Lol", 5);

		p1.decreaseGrade();
		std::cout << p1 << std::endl;

		p2.increaseGrade();
		std::cout << p2 << std::endl;

		p1.increaseGrade();
		std::cout << p1 << std::endl;
	}
	catch(const std::exception& e)//константная ссылка на объекти типа xeption
	{
		std::cerr << e.what() << std::endl;
	}
}

/*
	try(пытаться) — начало блока исключений
	catch(поймать) — начало блока, "ловящего" исключение
	throw(бросить) —  ключевое слово, "создающее" ("возбуждающее") исключение
*/

// Обработка исключений - исключительных ситуация (проблем в работе программы)
// std::exception - базовый клас с++ обрабатывающий исключения
// Все классы обработки исключений создаются путем наследования его
// Функция what возвращает: указатель на строку с завершающим нулем с поясняющей информацией

//std::exception can может использоваться как он есть
//но если юзер хочет определенную ошибку, то он может унаследовать
//std::exception и задефайнить ошибку как в коде выше(CustomException)
