/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:13:20 by nolecler          #+#    #+#             */
/*   Updated: 2025/10/14 09:43:51 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>
// #include <deque>
// #include <list>

int main()
{
    std::vector<int> v;
    // std::deque<int> v;
    // std::list<int> v;

    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 6);
        // std::deque<int>::iterator it = easyfind(v, 6);
        // std::list<int>::iterator it = easyfind(v, 6);
        
        std::cout << "Element found is " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(v, 3);
        // std::deque<int>::iterator it = easyfind(v, 3);
        // std::list<int>::iterator it = easyfind(v, 3);
        std::cout << "Element found is " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}