#ifndef ITER_HPP
#define ITER_HPP
// Шаблон функции iter, принимает 3 параметра
// 1 - Адрес массива
// 2 - Длина массива
// 3 - Функция, которая будет вызываться для каждого элемента массива
template< typename T>
void iter(T* arrPtr, int size, void (*f)(T &arrPtr))
{
	for (int i = 0; i < size; i++)
		f(arrPtr[i]);
}

template <typename T>
void f(T &arg)  
{
	std::cout  << "|" << arg << "| " << std::endl;
}

#endif