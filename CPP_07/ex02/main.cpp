#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> arrayOne(8);
    try
    {
        std::cout << arrayOne[12] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "------------------------" << std::endl;
    unsigned int i = 0;
    Array<char> arrayTwo(8);
    for(i = 0; i < arrayTwo.size(); i++)
        arrayTwo[i] = 'a' + i;
    i = 0;
    try
    {
        for(i = 0; i < arrayTwo.size(); i++)
            std::cout << '|' << arrayTwo[i] << '|';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    i = 0;
    Array<double> arrayThree(8);
    for(i = 0; i < arrayThree.size(); i++)
        arrayThree[i] = i + 0.69;
    i = 0;
    try
    {
        for(i = 0; i < arrayTwo.size(); i++)
            std::cout << arrayThree[i] << '|';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;   
    return (0);
}