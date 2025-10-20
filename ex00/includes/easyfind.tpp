/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:19:27 by nolecler          #+#    #+#             */
/*   Updated: 2025/10/18 14:20:15 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int nb)
{
    typename T::iterator it = std::find(container.begin(), container.end(), nb);
    if (it != container.end())
        return (it);
    else
        throw NotFoundException();
}

const char* NotFoundException::what()const throw()
{
    return ("Element not found.");
}