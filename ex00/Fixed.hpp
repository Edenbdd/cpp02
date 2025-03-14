/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:39:48 by aubertra          #+#    #+#             */
/*   Updated: 2025/03/14 15:57:45 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed const &src);
        ~Fixed();
        int		getRawBits(void) const;
        void	setRawBits(int const raw);
        Fixed	&operator=(Fixed const &to_assign);
    private:
        int					_nb;
        static const int	_bits = 8;
};

#endif