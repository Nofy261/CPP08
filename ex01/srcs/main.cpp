/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:05:10 by nolecler          #+#    #+#             */
/*   Updated: 2025/10/14 10:24:09 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

//tester le Span avec au moins 10 000 nombres.(sujet)
int main()
{
    std::cout << "**************************" <<std::endl;
    // un seul element dans le tab
    {
        Span sp(3);
        try
        {
            sp.addNumber(36);
            sp.longestSpan();
            std::cout << sp.longestSpan() << std::endl;

        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "**************************" <<std::endl;
    // Test de dépassement de la taille max
    {
        Span sp(4);
        try
        {
            sp.addNumber(1);
            sp.addNumber(4);
            sp.addNumber(5);
            sp.addNumber(67);

            sp.printTab();
            std::cout << sp.longestSpan() << std::endl;
            std::cout << sp.shortestSpan() << std::endl;

            sp.addNumber(2);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "**************************" <<std::endl;
    // test addMultiple
    try
    {
        Span sp(4);

        std::vector<int> v;
        v.push_back(54);
        v.push_back(-2147483648);
        v.push_back(33);
        v.push_back(2147483647);

        sp.addMultiple(v.begin(), v.end());
       
        sp.printTab();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}