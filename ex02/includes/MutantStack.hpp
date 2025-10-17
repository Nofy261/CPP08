


#pragma once
#include <stack>
#include <deque>
#include <iostream>


//la class est un template donc pourra utiliser int, string etc...
// 
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public :
        MutantStack();
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();

        typedef typename Container::iterator		iterator;
        typedef typename Container::const_iterator      const_iterator;

        iterator begin(); //lire et ecrire ,on peut modifier les elements
        iterator end();

        const_iterator begin()const; // lecture seulement , element non modifiable
        const_iterator end()const;

};

#include "MutantStack.tpp"