/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:39:38 by aubertra          #+#    #+#             */
/*   Updated: 2025/03/14 16:43:02 by aubertra         ###   ########.fr       */
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
}

Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_nb = n;
    return ;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    this->_nb = f;
    return ;
}

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

float   Fixed::toFloat(void) const
{
    return (this->_nb);
}


int     Fixed::toInt(void) const
{
    return (this->_nb);
}


Fixed	&Fixed::operator=(Fixed const &to_assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &to_assign)
        this->_nb = to_assign._nb;
    return (*this);
}

std::ostream    &operator<<(std::ostream &o, Fixed const &to_print)
{
    o << to_print.toFloat();
    return (o);
}
