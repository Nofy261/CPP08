/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:05:06 by nolecler          #+#    #+#             */
/*   Updated: 2025/10/15 10:56:20 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>


// Le sujet demande  de tester le Span avec au moins 10 000 nombres.
// un objet span est un objet capable de stocker des entiers
class Span
{
    public :
        Span();
        Span(unsigned int N); // N nombre max d'entiers a stocker
        Span(const Span &copy);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int n);
        unsigned int shortestSpan()const;
        unsigned int longestSpan()const;

        
        // depassement de capacite
        class OutOfRangeException : public std::exception
        {
            public :
                const char* what() const throw();
            
        };

        //Pas assez d'elements dans le tableau
        class InvalidElementException : public std::exception
        {
            public :
                const char* what() const throw();
            
        };

        //sert a ajouter plusieurs elements en une seule fois 
        template <typename InputIterator>
        void addNb(InputIterator begin, InputIterator end)// ajoute plusieus entier au span en une seule fois , si depasse N throw exception
        {
            unsigned int availableSpace = this->_sizeMax - _tab.size();//_tab.size permet de savoir le nombre d'elements present dans tab
            if (availableSpace == 0)
                throw OutOfRangeException();
            //calculer combien d'element on veut ajouter
            unsigned int numToAdd = std::distance(begin, end);

            //verifier si ca rentre dans la capacite
            if (numToAdd > availableSpace) // depasse le nombre de place dispo
                throw OutOfRangeException();
            else
                _tab.insert(_tab.end(), begin, end); // on ajoute
            // iterator insert(iterator pos, InputIterator first, InputIterator last); -> retourne un iterateur sur l element inserer  
        }

    private :
        unsigned int _sizeMax;
        std::vector<int> _tab; 
};