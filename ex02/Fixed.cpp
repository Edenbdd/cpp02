/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:39:38 by aubertra          #+#    #+#             */
/*   Updated: 2025/03/15 12:17:13 by aubertra         ###   ########.fr       */
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
    this->_nb = n << this->_bits;
    return ;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    this->_nb = roundf(f * (1 << this->_bits));
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
    float   result;
    
    result = ((float)this->_nb / (1 << this->_bits));
    return (result);
}


int     Fixed::toInt(void) const
{
    int result;

    result = this->_nb >> this->_bits;
    return (result);
}


Fixed	&Fixed::operator=(Fixed const &to_assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &to_assign)
        this->_nb = to_assign._nb;
    return (*this);
}

Fixed	&Fixed::operator>(Fixed const &rhs)
{
    
}

Fixed	&Fixed::operator<(Fixed const &rhs)
{

}

Fixed	&Fixed::operator>=(Fixed const &rhs)
{

}

Fixed	&Fixed::operator<=(Fixed const &rhs)
{
    
}

Fixed	&Fixed::operator==(Fixed const &rhs)
{
    
}
Fixed	&Fixed::operator!=(Fixed const &rhs)
{
    
}
Fixed	&Fixed::operator+(Fixed const &rhs)
{
    
}
Fixed	&Fixed::operator-(Fixed const &rhs)
{
    
}
Fixed	&Fixed::operator*(Fixed const &rhs)
{
    
}
Fixed	&Fixed::operator/(Fixed const &rhs)
{
    
}
Fixed	&Fixed::operator++(void)
{
    
}
Fixed	&Fixed::operator++(void)
{
    
}
Fixed	&Fixed::operator--(void)
{
    
}
Fixed	&Fixed::operator--(void)
{
    
}

std::ostream    &operator<<(std::ostream &o, Fixed const &to_print)
{
    o << to_print.toFloat();
    return (o);
}
