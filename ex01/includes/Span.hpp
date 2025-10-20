/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:05:06 by nolecler          #+#    #+#             */
/*   Updated: 2025/10/18 14:13:59 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <exception>
#include <iterator>

class Span
{
    public :
        Span();
        Span(unsigned int N);
        Span(const Span &copy);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int n);
        unsigned int shortestSpan()const;
        unsigned int longestSpan()const;
        void printTab()const;
       
        class OutOfRangeException : public std::exception
        {
            public :
                const char* what() const throw();
            
        };

        class InvalidElementException : public std::exception
        {
            public :
                const char* what() const throw();
            
        };

        template <typename InputIterator>
        void addMultiple(InputIterator begin, InputIterator end)
        {
            unsigned int availableSpace = this->_sizeMax - _tab.size();
            if (availableSpace == 0)
                throw OutOfRangeException();
            unsigned int numToAdd = std::distance(begin, end);
            if (numToAdd > availableSpace)
                throw OutOfRangeException();
            else
                _tab.insert(_tab.end(), begin, end); 
        }

    private :
        unsigned int _sizeMax;
        std::vector<int> _tab; 
};