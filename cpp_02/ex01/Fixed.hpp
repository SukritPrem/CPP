#ifndef FIXED_H
# define FIXED_H
#include <iostream>

class Fixed{
    private:
        int _fixed;
        static const int _fractional_bits = 8;
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(Fixed &origin);
        Fixed(Fixed const &origin);

        Fixed(const int number);
        Fixed(const float number);

        float toFloat( void ) const;
        int toInt( void ) const;

        Fixed& operator=(const Fixed& other);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &o, Fixed const &r_obj);
#endif