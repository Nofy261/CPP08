/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:05:14 by nolecler          #+#    #+#             */
/*   Updated: 2025/10/14 11:34:33 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"








unsigned int Span::longestSpan()const
{
    if (this->_nb.size() < 2)
        throw SpanException();
    // trouver max et min element 
    // on retourne max - min


    
}

const char* Span::SpanException::what()const throw()
{
    return ("Invalid element or Error of capacity");
}