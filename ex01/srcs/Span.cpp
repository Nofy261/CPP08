/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:05:14 by nolecler          #+#    #+#             */
/*   Updated: 2025/10/18 14:27:13 by nolecler         ###   ########.fr       */
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
    if (_tab.size() >= _sizeMax)
        throw OutOfRangeException();
    else
        _tab.push_back(n);
}

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
    long long minDiff = LLONG_MAX;
    if (this->_tab.size() < 2)
        throw InvalidElementException();
    std::vector<int> tabCopy = _tab;
    std::sort(tabCopy.begin(), tabCopy.end()); 
    for (unsigned int i = 0; i < tabCopy.size() - 1; i++)
    {
        tmp = static_cast<long long>(tabCopy[i + 1]) - static_cast<long long>(tabCopy[i]);
        if (tmp < minDiff)
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