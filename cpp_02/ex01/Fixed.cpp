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

Fixed::Fixed(Fixed const &origin)
{
    std::cout << "Copy construtor called" << std::endl;
    *this = origin;
}

int    Fixed::getRawBits(void) const{return _fixed ;}

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

Fixed::Fixed(const int number)
{
    std::cout << "Int construtor called" << std::endl;
    _fixed = number << _fractional_bits;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float construtor called" << std::endl;
    _fixed = roundf(number * (1 << _fractional_bits));
}

float   Fixed::toFloat( void ) const
{
    return ((float)_fixed / (1 << _fractional_bits));
}

int     Fixed::toInt( void ) const
{
    return (_fixed >> _fractional_bits);
}

std::ostream& operator<<(std::ostream &o, Fixed const &r_obj)
{
    o << r_obj.toFloat();

    return o;
}
