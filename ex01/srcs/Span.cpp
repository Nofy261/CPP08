/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:05:14 by nolecler          #+#    #+#             */
/*   Updated: 2025/10/15 10:58:20 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <climits>
#include <exception>

Span::Span() : _sizeMax(0)
{}

Span::Span(unsigned int N) : _sizeMax(N)
{}

Span::Span(const Span &copy) : _sizeMax(copy._sizeMax), _tab(copy._tab)
{}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_sizeMax = other._sizeMax;
        this->_tab = other._tab;
    }
    return (*this);
}

Span::~Span(){}


void Span::addNumber(int n)
{
    if (_tab.size() >= _sizeMax) // la taille de stockage est depassé
        throw OutOfRangeException();
    else
        _tab.push_back(n);
}


// cas a tester intmax - int min = overflow d ou le cast en long long
unsigned int Span::longestSpan()const
{
    if (this->_tab.size() < 2)
        throw InvalidElementException();
    
    std::vector<int>::const_iterator min = std::min_element(_tab.begin(), _tab.end());
    std::vector<int>::const_iterator max = std::max_element(_tab.begin(), _tab.end());
    
    long long diff = static_cast<long long>(*max) - static_cast<long long>(*min);
    return static_cast<unsigned int>(diff); 
}

unsigned int Span::shortestSpan()const
{
    long long tmp = 0;
    long long minDiff = LLONG_MAX; // init de la plus petite difference
    if (this->_tab.size() < 2)
        throw InvalidElementException();
    std::vector<int> tabCopy = _tab; //copie car const non modifiable
    std::sort(tabCopy.begin(), tabCopy.end()); // ->_tab = {1, 3, 4, 9} puis on compare 3-1 = 2; 4-3=1; 9-4=5 donc le plus petit =1 
    for (unsigned int i = 0; i < tabCopy.size() - 1; i++)
    {
        tmp = static_cast<long long>(tabCopy[i + 1]) - static_cast<long long>(tabCopy[i]);//on fait la soustraction en long pour eviter l overflow
        if (tmp < minDiff) // comparer l ecart entre chaque paire voisine
            minDiff = tmp;
    } 
    return (static_cast<unsigned int>(minDiff));
}


const char* Span::OutOfRangeException::what()const throw()
{
    return ("Cannot add number — capacity exceeded or no elements present.");
}

const char* Span::InvalidElementException::what()const throw()
{
    return ("insufficient elements or empty container.");
}

void Span::printTab() const
{
    for (unsigned int i = 0; i < _tab.size(); i++)
    {
        std::cout << _tab[i] << " ";
    }
    std::cout << std::endl;
}