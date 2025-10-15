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



unsigned int Span::longestSpan()const
{
    if (this->_tab.size() < 2)
        throw InvalidElementException();
    
    std::vector<int>::iterator min = std::min_element(_tab.begin(), _tab.end());
    std::vector<int>::iterator max = std::max_element(_tab.begin(), _tab.end());
    
    return (*max - *min);  
}

unsigned int Span::shortestSpan()const
{
    // verif qu'il y a au moins 2nombres
    // Trier les nbres
    // comparer l ecart entre chaque paire voisine
    // retourne la plus petite difference trouvee
}




const char* Span::OutOfRangeException::what()const throw()
{
    return ("Cannot add number — capacity exceeded.");
}

const char* Span::InvalidElementException::what()const throw()
{
    return ("insufficient elements.");
}