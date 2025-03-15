/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:38:18 by aubertra          #+#    #+#             */
/*   Updated: 2025/03/15 15:57:39 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    {
    std::cout << "Tests from subject: " << std::endl;
    Fixed a;
    Fixed const b( Fixed(5.05f) * Fixed(2) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl; 

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;
    }
    {
    // std::cout << "Additional Tests: " << std::endl;
    // Fixed c;
    // Fixed const d( Fixed(5.05f) * Fixed(2) );
    // std::cout << c << std::endl;
    // std::cout << --c << std::endl;
    // std::cout << c << std::endl;
    // std::cout << c-- << std::endl; 
    // std::cout << c << std::endl;

    // std::cout << d << std::endl;

    // std::cout << Fixed::min(c, d) << std::endl;
    }
    return (0);
}
