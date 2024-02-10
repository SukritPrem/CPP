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

        bool operator< (Fixed const &r_obj) const;
        bool operator> (Fixed const &r_obj) const;
        bool operator<=(Fixed const &r_obj) const;
        bool operator>=(Fixed const &r_obj) const;
        bool operator==(Fixed const &r_obj) const;
        bool operator!=(Fixed const &r_obj) const;

        Fixed operator+ (Fixed const &r_obj) const;
        Fixed operator- (Fixed const &r_obj) const;
        Fixed operator* (Fixed const &r_obj) const;
        Fixed operator/ (Fixed const &r_obj) const;

        Fixed & operator++ (void);
        Fixed operator++ (int);
        Fixed & operator-- (void);
        Fixed operator-- (int);

        const static Fixed & min(Fixed &l_obj, Fixed &r_obj);
        const static Fixed & min(Fixed const &l_obj, Fixed const &r_obj);
        const static Fixed & max(Fixed &l_obj, Fixed &r_obj);
        const static Fixed & max(Fixed const &l_obj, Fixed const &r_obj);
};

std::ostream& operator<<(std::ostream &o, Fixed const &r_obj);

#endif