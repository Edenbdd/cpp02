/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:39:48 by aubertra          #+#    #+#             */
/*   Updated: 2025/03/15 14:49:07 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define EPSILON  	0.00390625

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed const &src);
        Fixed(int const n);
        Fixed(float const f);
        ~Fixed();
        int		            getRawBits(void) const;
        void	            setRawBits(int const raw);
        Fixed               &operator=(Fixed const &rhs);
        bool	            operator>(Fixed const &rhs) const;
        bool	            operator<(Fixed const &rhs) const;
        bool	            operator>=(Fixed const &rhs) const;
        bool	            operator<=(Fixed const &rhs) const;
        bool	            operator==(Fixed const &rhs) const;
        bool	            operator!=(Fixed const &rhs) const;
        Fixed	            &operator+(Fixed const &rhs);
        Fixed	            &operator-(Fixed const &rhs);
        Fixed	            &operator*(Fixed const &rhs);
        Fixed	            &operator/(Fixed const &rhs);
        Fixed	            &operator++(void);
        Fixed	            &operator++(int);
        Fixed	            &operator--(void);
        Fixed	            &operator--(int);
        float               toFloat( void ) const;
        int                 toInt( void ) const;
        Fixed static        &min(Fixed &a, Fixed &b);
        Fixed static const  &min(Fixed const &a, Fixed const &b);
        Fixed static        &max(Fixed &a, Fixed &b);
        Fixed static const  &max(Fixed const &a, Fixed const &b);

    private:
        int					_nb;
        static const int	_bits = 8;
};

//add surchage operateur << AVANT DE PRINT QUOIQUE CE SOIT
std::ostream    &operator<<(std::ostream &o, Fixed const &to_print);
#endif