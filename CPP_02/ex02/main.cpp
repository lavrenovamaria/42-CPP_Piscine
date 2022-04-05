#include "Fixed.hpp"
// Шесть операторов сравнения: >, ><, >=, <, >
// Четыре арифметических оператора: +, -, * и /

// Приращение — величина на котор. что-либо увеличивается / До, после + /
// Уменьшение / (префиксный)До, (постфиксный)после -


int main()
{
    Fixed a;
    Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << Fixed::min( a, b ) << std::endl;

    a = 1;
    b = 3.14f;

    std::cout << b << " < " << a << " -- " << (b < a) << std::endl;
    std::cout << b << " <= " << a << " -- " << (b <= a) << std::endl;
    std::cout << b << " > " << a << " -- " << (b > a) << std::endl;
    std::cout << b << " >= " << a << " -- " << (b >= a) << std::endl;
    std::cout << b << " == " << a << " -- " << (b == a) << std::endl;
    std::cout << b << " != " << a << " -- " << (b != a) << std::endl;

    a = 3.14f;

    std::cout << b << " < " << a << " -- " << (b < a) << std::endl;
    std::cout << b << " <= " << a << " -- " << (b <= a) << std::endl;
    std::cout << b << " > " << a << " -- " << (b > a) << std::endl;
    std::cout << b << " >= " << a << " -- " << (b >= a) << std::endl;
    std::cout << b << " == " << a << " -- " << (b == a) << std::endl;
    std::cout << b << " != " << a << " -- " << (b != a) << std::endl;

    b = 6.28f;

    std::cout << b << " + " << a << " -- " << (b + a) << std::endl;
    std::cout << b << " - " << a << " -- " << (b - a) << std::endl;
    std::cout << b << " * " << a << " -- " << (b * a) << std::endl;
    std::cout << b << " / " << a << " -- " << (b / a) << std::endl;

    return 0;
}
