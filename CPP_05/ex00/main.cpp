#include  <exception>
#include  <iostream>
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

class  CustomException
	: 	public std :: exception
{
	public :
		const  char *  what ( void )  const  throw ( )
		{
			return  ( "CustomException" ) ;
		}
} ;

int  main ( void )
{
	while  ( true )
	{
		try
		{
			std ::string key ;
			while  ( true )
			{
				std :: cin >> key ;
				if  ( key ==  "cause" )
					throw  ( CustomException ( ) ) ;
				if  ( key ==  "int" )
				  throw  ( 10 ) ;
				if  ( key ==  "double" )
					throw  ( 0.5 ) ;
			}
		}
		catch  ( std ::exception & e )
		{
			std :: cerr << e . what ( )  << std :: endl ;
		}
		catch  ( int & i )
		{
			std :: cerr <<  "Int Caught"  << std :: endl ;
		}
		catch  ( double & d )
		{
			std :: cerr <<  "Double Caught"  << std ::endl ;
		}
		std :: cout <<  "Program End Normally"  << std :: endl ;
	}
	return  ( 0 ) ;
}
