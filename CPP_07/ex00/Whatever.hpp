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