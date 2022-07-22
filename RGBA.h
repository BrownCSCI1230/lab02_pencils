#ifndef RGBA_H
#define RGBA_H

// A structure for a color.  Each channel is 8 bits [0-255].
struct RGBA {
    RGBA() : r(0), g(0), b(0), a(255) {}
    RGBA(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255)
        : r(red), g(green), b(blue), a(alpha) {}

    union {
        struct { unsigned char r, g, b, a; };
        unsigned char channels[4];
    };

    RGBA operator+(const RGBA &c1) const;
    RGBA operator-(const RGBA &c1) const;
    RGBA operator*(const RGBA &c1) const;
    RGBA operator/(const RGBA &c1) const;

    friend bool operator==(const RGBA &c1, const RGBA &c2);
    friend bool operator!=(const RGBA &c1, const RGBA &c2);
};

#endif // RGBA_H
