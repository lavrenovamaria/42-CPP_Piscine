#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
//базовый класс, от которого будем наследоваться
class Animal
{
	protected:
		std::string type;
		//чем мы делимся с наследником
	public:
		Animal();
		Animal(const Animal &src);
		// копируем класс для других инициализаций и передачи объектов
		virtual ~Animal();

		Animal          &operator=(const Animal &newValue);
		// Перегрузка операторов
		// Верну ссылку на текущее значение объекта/экземпляр
		std::string     getType() const;
		virtual void    makeSound() const;
		//этим странным синтаксисом мы определяем
		//нереализованную "интерфейсную" функцию
};

#endif
