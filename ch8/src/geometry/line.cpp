// Implementation of Line class

#include <cmath>
#include <iostream>

#include "line.hpp"

// Constructors ####################################################################################

Line::Line(Point p1, Point p2) {
    p1_ = p1;
    p2_ = p2;
}

// Member functions ################################################################################

Real Line::distance(const Point& point) const {
    std::cout << "Not Implemented Error! " << point << std::endl;
    return 0.0;
}

// Member attributes ###############################################################################

Point& Line::p1() {
    return p1_;
}

const Point& Line::p1() const {
    return p1_;
}

Point& Line::p2() {
    return p2_;
}

const Point& Line::p2() const {
    return p2_;
}
