#include "Figures.h"
#include <iostream>
#include <string>

int rect::area() const { return _h * _w; }

void rect::draw() const {
    for (int i = 0; i < _h; i++) {
        for (int i = 0; i < _w; i++) {
            std::cout << "#";
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void rect::cdraw() const { std::cout << "W:" << _w << ",H:" << _h << std::endl; }