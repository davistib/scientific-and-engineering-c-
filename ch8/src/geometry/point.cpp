// Implementation of Point class
#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

#include "point.hpp"
#include "line.hpp"

// Constructors ####################################################################################

Point::Point() {}

Point::Point(Real x, Real y, Real z)
    :
    x_(x),
    y_(y),
    z_(z) {}

// Member functions ################################################################################

Real Point::distance(const Point& point = Point()) const {

    Real distance = std::sqrt(
        std::pow(x_ - point.x(), 2) +
        std::pow(y_ - point.y(), 2) +
        std::pow(z_ - point.z(), 2)
    );

    return distance;
}

Real Point::distance(const Line& line) const {
    return line.distance(*this);
}

Real Point::angle(const Point& p1, const Point& p2) const {
    Point v1 = p1 - *this;
    Point v2 = p2 - *this;
    Point v3 = v1 * v2;
    Real dot = v3.x_ + v3.y_ + v3.z_;
    Real a = std::acos( dot / (v1.distance() * v2.distance()) );
    return a * 180.0 / M_PI;
}

// Member attributes ###############################################################################

Real& Point::x() {
    return x_;
}

Real Point::x() const {
    return x_;
}

Real& Point::y() {
    return y_;
}

Real Point::y() const {
    return y_;
}

Real& Point::z() {
    return z_;
}

Real Point::z() const {
    return z_;
}

// Operator functions ##############################################################################

Point& Point::operator+=(Real num) {
    x_ += num;
    y_ += num;
    z_ += num;
    return *this;
}

Point& Point::operator+=(const Point& rhs) {
    x_ += rhs.x();
    y_ += rhs.y();
    z_ += rhs.z();
    return *this;
}

Point& Point::operator-=(const Point& rhs) {
    x_ -= rhs.x();
    y_ -= rhs.y();
    z_ -= rhs.z();
    return *this;
}

Point& Point::operator*=(const Point& rhs) {
    x_ *= rhs.x();
    y_ *= rhs.y();
    z_ *= rhs.z();
    return *this;
}

Point& Point::operator/=(const Point& rhs) {
    x_ /= rhs.x();
    y_ /= rhs.y();
    z_ /= rhs.z();
    return *this;
}

Point operator+(const Point& lhs, Real num) {
    Point result(lhs);
    return result += num;
}

Point operator+(const Point& lhs, const Point& rhs) {
    Point result(lhs);
    return result += rhs;
}

Point operator-(const Point& lhs, const Point& rhs) {
    Point result(lhs);
    return result -= rhs;
}

Point operator*(const Point& lhs, const Point& rhs) {
    Point result(lhs);
    return result *= rhs;
}

Point operator/(const Point& lhs, const Point& rhs) {
    Point result(lhs);
    return result /= rhs;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "Point(" << p.x() << ", " << p.y() << ", " << p.z() << ")";
}

void operator>>(std::istream& in, Point& p) {
    in >> p.x_ >> p.y_ >> p.z_;
}
