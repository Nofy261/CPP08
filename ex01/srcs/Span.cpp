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

//si taille = 0 a gerer?
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
    
    long long diff = static_cast<long long>(*max) - static_cast<long long>(*min);
    return static_cast<unsigned int>(diff); 
}

unsigned int Span::shortestSpan()const
{
    long long minDiff; // la plus petite difference
    long long tmp;

    minDiff = LLONG_MAX;
    tmp = 0;
    // verif qu'il y a au moins 2nombres
    if (this->_tab.size() < 2)
        throw InvalidElementException();
    // std::sort(iterator first, iterator last);
    // on met dans l'ordre croissant puis on calcul l ecart entre chaque voisin 
    std::sort(_tab.begin(), _tab.end()); // ->_tab = {1, 3, 4, 9} puis on compare 3-1 = 2; 4-3=1; 9-4=5 donc le plus petit =1 
    for (unsigned int i = 0; i < _tab.size() - 1; i++)
    {
        //on fait la soustraction en long pour eviter l overflow
        tmp = static_cast<long long>(_tab[i + 1]) - static_cast<long long>(_tab[i]);
        if (tmp < minDiff) // comparer l ecart entre chaque paire voisine
            minDiff = tmp;
    } 
    return (static_cast<unsigned int>(minDiff)); // retourne la plus petite difference trouvee
}


const char* Span::OutOfRangeException::what()const throw()
{
    return ("Cannot add number — capacity exceeded.");
}

const char* Span::InvalidElementException::what()const throw()
{
    return ("insufficient elements.");
}