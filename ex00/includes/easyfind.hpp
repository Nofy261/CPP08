/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:13:16 by nolecler          #+#    #+#             */
/*   Updated: 2025/10/14 09:20:06 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iterator>
#include <iostream>
 #include <algorithm> 

class NotFoundException : public std::exception
{
    public :
        const char* what()const throw();  
};

template <typename T>
typename T::iterator easyfind(T& container, int nb);

#include "easyfind.tpp"