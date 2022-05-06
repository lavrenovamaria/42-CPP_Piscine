#include <iostream>
#include <cassert>
#include "Whatever.hpp"

int main()
{
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "max(a, b) = "  << ::max(a, b) << std::endl;
    std::cout << "min(a, b) = "  << ::min(a, b) << std::endl;

    std::cout << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    
    std::cout << std::endl;
    char s1 = 'A';
    char s2 = 'S';

    ::swap(s1, s2);
    std::cout << "s2 = " << s2 << ", s1 = " << s1 << std::endl;
    std::cout << "max(s2, s1) = " << ::max(s2, s1) << std::endl;
    std::cout << "min(s2, s1) = " << ::min(s2, s1) << std::endl;

    return (0);
}