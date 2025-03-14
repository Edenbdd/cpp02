/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:39:38 by aubertra          #+#    #+#             */
/*   Updated: 2025/03/15 16:16:40 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*CANONICAL*/////////////////////////////////////////////////
Fixed::Fixed():_nb(0)
{
    // std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(Fixed const &src)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Fixed::Fixed(int const n)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_nb = n << this->_bits;
    return ;
}

Fixed::Fixed(float const f)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_nb = roundf(f * (1 << this->_bits));
    return ;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
    return ;
}
/*GET & SET*/////////////////////////////////////////////////
int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->_nb);
}

void	Fixed::setRawBits(int const raw)
{
    this->_nb = raw;
    return ;
}
/*OPERATORS*///////////////////////////////////////////////////////////

Fixed	&Fixed::operator=(Fixed const &to_assign)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &to_assign)
        this->_nb = to_assign._nb;
    return (*this);
}

bool    Fixed::operator>(Fixed const &rhs) const
{
    return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
    return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
    return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
    return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator==(Fixed const &rhs)  const
{
    return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
    return (this->toFloat() != rhs.toFloat());
}

Fixed	Fixed::operator+(Fixed const &rhs)
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &rhs)
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &rhs)
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &rhs)
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	Fixed::operator++(void)
{
    this->_nb += 1;
    return (*this);
}

Fixed	Fixed::operator--(void)
{
    this->_nb -= 1;
    return (*this);
}

Fixed	Fixed::operator--(int)
{
    Fixed   temp = *this;
    this->_nb -= 1;
    return (temp);
}

Fixed	Fixed::operator++(int)
{
    Fixed   temp = *this;
    this->_nb += 1;
    return (temp);
}

std::ostream    &operator<<(std::ostream &o, Fixed const &to_print)
{
    o << to_print.toFloat();
    return (o);
}

/*PUBLICS FUNCTIONS*/////////////////////////////////////////////////

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

Fixed  &Fixed::min(Fixed &a, Fixed &b)
{
    if (a <= b)
        return (a);
    else
        return (b);
}

Fixed const  &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a <= b)
        return (a);
    else
        return (b);
}

Fixed  &Fixed::max(Fixed &a, Fixed &b)
{
    if (a >= b)
        return (a);
    else
        return (b);
}

Fixed const  &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a >= b)
        return (a);
    else
        return (b);
}
