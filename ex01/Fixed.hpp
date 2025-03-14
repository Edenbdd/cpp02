/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:39:48 by aubertra          #+#    #+#             */
/*   Updated: 2025/03/14 17:26:52 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed const &src);
        Fixed(int const n);
        Fixed(float const f);
        ~Fixed();
        int		getRawBits(void) const;
        void	setRawBits(int const raw);
        Fixed	&operator=(Fixed const &to_assign);
        float   toFloat( void ) const;
        int     toInt( void ) const;
    private:
        int					_nb;
        static const int	_bits = 8;
};

//add surchage operateur << AVANT DE PRINT QUOIQUE CE SOIT
std::ostream    &operator<<(std::ostream &o, Fixed const &to_print);
#endif