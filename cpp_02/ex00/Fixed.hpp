#include <iostream>

class Fixed{
    private:
        int _fixed;
        static const int _fractional_bits;
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(Fixed &origin);
        Fixed& operator=(const Fixed& other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};