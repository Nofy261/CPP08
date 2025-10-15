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

        
        //sert a ajouter plusieurs elements en seule fois 
        template <typename InputIterator>
        void addNumber(InputIterator begin, InputIterator end)// ajoute un entier au span , si depasse N throw exception
        {
            //calculer combien d'element on veut ajouter
            //verifier si ca rentre dans la capacite
            //si oui on les ajoute 
            //sinon exception lancee            
        }
        
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
        
        // Remplissage impossible si le tableau est pleine
        // Remplissage impossible si le tableau est vide ou ne contient que 1 nombre
        
        // longestSpan et shortestSpan = fct qui va retourner le plus grand ecart ou le plus petit ecart
        // mais il doit y avoir au moins 2 nombres sinon exception
        // ces deux fonction recoit un tableau;
        //Fct qui calcule le plus petit ecart 
        // si span = [1, 2, 3, 4];
        // resultat = 2 - 1 = 1
        
    


    private :
        unsigned int _sizeMax;
        std::vector<int> _tab; 

};