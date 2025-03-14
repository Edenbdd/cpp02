/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:39:38 by aubertra          #+#    #+#             */
/*   Updated: 2025/03/14 16:01:15 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_nb(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
};

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_nb);
}

void	Fixed::setRawBits(int const raw)
{
    this->_nb = raw;
    return ;
}

Fixed	&Fixed::operator=(Fixed const &to_assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &to_assign)
        this->_nb = to_assign.getRawBits();
    return (*this);
}