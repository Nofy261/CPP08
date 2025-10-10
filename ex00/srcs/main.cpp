/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:13:20 by nolecler          #+#    #+#             */
/*   Updated: 2025/10/10 11:43:34 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v = {1, 2, 3, 4};
    std::vector<int>::iterator it; 
    
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Element found is " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
       
}