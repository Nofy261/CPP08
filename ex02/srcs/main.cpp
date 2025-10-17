

#include "MutantStack.hpp"
#include <list>
#include <iostream>

// int main()
// {

//     MutantStack<int> mut;
//     mut.push(2);
//     mut.push(5);
//     mut.push(7);
//     mut.push(10);
//     mut.push(34);

//     std::cout << "Size : " << mut.size() << std::endl; 
//     std::cout << "Top : " << mut.top() << std::endl; // affiche
//     mut.pop(); // enleve
//     std::cout << "New top : " <<mut.top() << std::endl;
//     std::cout << "New size : " << mut.size() << std::endl;

//     std::cout << "*********************" << std::endl;

//     // test iterator
//     for (MutantStack<int>::iterator it = mut.begin(); it != mut.end(); it++)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     std::cout << "*********************" << std::endl;
//     //test const_iterator

//     const MutantStack<int> constMut = mut; // mut est non const donc ok , l inverse est impossible
//     for (MutantStack<int>::const_iterator it = constMut.begin(); it != constMut.end(); it++)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     std::cout << "*********************" << std::endl;

//     return (0);
// }


int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    
    mstack.push(0); //[5 3 5 737 0];
    std::cout << "MutantStack size: " << mstack.size() << std::endl;
    std::cout << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
    std::stack<int> s(mstack);//on crée une pile s de type std::stack<int> en copiant le contenu de mstack.
    std::cout << "Top: " << s.top() << std::endl;
    std::cout << "Stack size: " << s.size() << std::endl;

    std::cout << "*************" << std::endl;
    // comparaison avec  std::list
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl; // au lieu de top()
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::cout << std::endl;

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    std::cout << std::endl;
    std::stack<int, std::list<int> > l(lst);
    std::cout << "List size: " << l.size() << std::endl;
    return 0;
}