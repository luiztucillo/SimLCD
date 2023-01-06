#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>

typedef struct {
    double r;       // a fraction between 0 and 1
    double g;       // a fraction between 0 and 1
    double b;       // a fraction between 0 and 1
} rgb;

typedef struct {
    double h;       // angle in degrees
    double s;       // a fraction between 0 and 1
    double v;       // a fraction between 0 and 1
} hsv;

class Color {
    public:    
        static hsv rgbToHsv(rgb in);
        static uint16_t rgbToInt(rgb color);

        static rgb hsvToRgb(hsv in);
        static uint16_t hsvToInt(hsv color);

        static rgb intToRgb(uint16_t color);
        static hsv intToHsv(uint16_t color);
};

#endif
