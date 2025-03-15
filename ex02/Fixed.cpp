/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:39:38 by aubertra          #+#    #+#             */
/*   Updated: 2025/03/15 14:10:38 by aubertra         ###   ########.fr       */
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
    if ((this->toFloat() - rhs.toFloat()) > EPSILON)
        return (true);
    return (false);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
    if ((rhs.toFloat()) - this->toFloat() > EPSILON)
        return (true);
    return (false);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
    if ((this->toFloat() - rhs.toFloat()) > EPSILON
        || (this->toFloat() - rhs.toFloat() < EPSILON 
        && this->toFloat() - rhs.toFloat() > 0)
        || (this->toFloat() - rhs.toFloat() == 0))
        return (true);
    return (false);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
    if ((rhs.toFloat() - this->toFloat()) > EPSILON
    || (rhs.toFloat() - this->toFloat() < EPSILON
    && rhs.toFloat() - this->toFloat() > 0)
    || (this->toFloat() - rhs.toFloat() == 0))
        return (true);
    return (false);
}

bool	Fixed::operator==(Fixed const &rhs)  const
{
    if ((rhs.toFloat() - this->toFloat() < EPSILON
    && rhs.toFloat() - this->toFloat() > 0)
    || (this->toFloat() - rhs.toFloat() == 0))
        return (true);
    return (false);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
    if (rhs.toFloat() - this->toFloat() > EPSILON
    || (this->toFloat() - rhs.toFloat() < 0))
        return (true);
    return (false);
}

Fixed	&Fixed::operator+(Fixed const &rhs)
{
    float   result;

    result = this->toFloat() + rhs.toFloat();
    Fixed   to_return(result);
    this->_nb = to_return._nb;
    return (*this);
}

Fixed	&Fixed::operator-(Fixed const &rhs)
{
    float   result;

    result = this->toFloat() - rhs.toFloat();
    Fixed   to_return(result);
    this->_nb = to_return._nb;
    return (*this);
}

Fixed	&Fixed::operator*(Fixed const &rhs)
{
    float   result;

    result = this->toFloat() * rhs.toFloat();
    Fixed   to_return(result);
    this->_nb = to_return._nb;
    return (*this);
}

Fixed	&Fixed::operator/(Fixed const &rhs)
{
    float   result;

    result = this->toFloat() / rhs.toFloat();
    Fixed   to_return(result);
    this->_nb = to_return._nb;
    return (*this);
}

Fixed	&Fixed::operator++(void)
{
    float   result;

    result = this->toFloat() + EPSILON;
    Fixed   to_return(result);
    this->_nb = to_return._nb;
    return (*this);
}

Fixed	&Fixed::operator--(void)
{
    float   result;

    result = this->toFloat() - EPSILON;
    Fixed   to_return(result);
    this->_nb = to_return._nb;
    return (*this);
}

Fixed	&Fixed::operator--(int unit)
{
    float   result;

    result = this->toFloat() - unit;
    Fixed   to_return(result);
    this->_nb = to_return._nb;
    return (*this);
}

Fixed	&Fixed::operator++(int unit)
{
    float   result;

    result = this->toFloat() + unit;
    Fixed   to_return(result);
    this->_nb = to_return._nb;
    return (*this);
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
