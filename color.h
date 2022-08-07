
#include "vec3.h"
#include <iostream> 

#ifndef COLOR_H
#define COLOR_H

void write_color(std::ostream & out, const color & pixel){
    out << (int) 255.999 * pixel.x << ' '
        << (int) 255.999 * pixel.y << ' '
        << (int) 255.999 * pixel.z << '\n';
}

#endif 