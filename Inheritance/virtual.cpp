# include  <iostream>

 class  A
{
	public :
		virtual  void  scream ( void )
		{
			std :: cout <<  "hi"  << std :: endl ;
		}
} ;

class  B  :  public  A
 {
	public :
		void  scream ( void )  const
		{
			std :: cout <<  "hello"  << std :: endl;
		}
} ;

int  main ( void )
{
	B b ;
	A	 * p =  & b ;

	b . scream ( ) ;
	p -> scream ( ) ;
	return  ( 0 ) ;
}
