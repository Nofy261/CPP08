

#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main()
{

    MutantStack<int> mut;
    mut.push(2);
    mut.push(5);
    mut.push(7);
    mut.push(10);
    mut.push(34);

    std::cout << "Size : " << mut.size() << std::endl; 
    std::cout << "Top : " << mut.top() << std::endl; // affiche
    mut.pop(); // enleve
    std::cout << "New top : " <<mut.top() << std::endl;
    std::cout << "New size : " << mut.size() << std::endl;

    std::cout << "*********************" << std::endl;

    // test iterator
    for (MutantStack<int>::iterator it = mut.begin(); it != mut.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "*********************" << std::endl;
    //test const_iterator

    const MutantStack<int> constMut = mut; // mut est non const donc ok , l inverse est impossible
    for (MutantStack<int>::const_iterator it = constMut.begin(); it != constMut.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    return (0);
}