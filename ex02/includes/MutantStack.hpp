/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:21:38 by nolecler          #+#    #+#             */
/*   Updated: 2025/10/18 14:25:22 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <deque>
#include <iostream>

 
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public :
        MutantStack();
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();

        typedef typename Container::iterator		iterator;
        typedef typename Container::const_iterator      const_iterator;

        iterator begin();
        iterator end();

        const_iterator begin()const;
        const_iterator end()const;

};

#include "MutantStack.tpp"