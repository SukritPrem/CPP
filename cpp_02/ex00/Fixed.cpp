#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    _fixed = 0;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed &origin)
{
    std::cout << "Copy construtor called" << std::endl;
    _fixed = origin.getRawBits();
}

int    Fixed::getRawBits(void) const{std::cout << "getRawBits member function called" << std::endl;return _fixed;}

void    Fixed::setRawBits(int const raw){_fixed = raw;}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) 
        _fixed = other.getRawBits();
    else
        std::cout << "Cannot copy to itself" << std::endl;
	return (*this);    
}
