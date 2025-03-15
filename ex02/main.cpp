/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aubertra <aubertra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:38:18 by aubertra          #+#    #+#             */
/*   Updated: 2025/03/15 16:35:51 by aubertra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    {
    std::cout << "Tests from subject (++, ++, +, >, <, max) " << std::endl;
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
    std::cout << "Additional Tests (--, --, -, <, >, min): " << std::endl;
    Fixed a;
    Fixed const b( Fixed(5.05f) * Fixed(2) );
    std::cout << "a : " << a << std::endl;
    std::cout << "--a : " << --a << std::endl;
    std::cout << "a : " << a << std::endl;
    std::cout << "a-- : " << a-- << std::endl;
    std::cout << "a : " << a << std::endl; 
    std::cout << "b : " << b << std::endl;
    std::cout << "min(a, b) : " << Fixed::min(a, b) << std::endl;
    }
    {
    std::cout << "Additional Tests (*, /, >=, ==, !=, <=): " << std::endl;
    Fixed a(Fixed(5.05f) / Fixed(2));
    Fixed const b( Fixed(5.05f) * Fixed(2));
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "a * b : " << a * b << std::endl;
    std::cout << "a / b : " << a / b << std::endl;
    std::cout << "(a != b) : " << (a != b) << std::endl;
    std::cout << "(a == b) : " << (a == b) << std::endl;
    std::cout << "(a <= b) : " << (a <= b) << std::endl;
    std::cout << "(a >= b) : " << (a >= b) << std::endl;
    }
    return (0);
}
