// Define a basic three-dimensional point class
#pragma once

#include <iostream>

#include "../types.hpp"

// #####################################################################################################################

class Line;  // forward declaration

class Point {

    public:
        // Constructors
        Point();
        Point(Real x, Real y, Real z);

        // Member functions
        Real distance(const Point&) const;
        Real distance(const Line&) const;

        /**
         * @brief Compute angle formed by 3 points, with this Point as the origin
         *
         * @param Point other Point
         * @param Point other Point
         *
         * @return angle in degrees
         */
        Real angle(const Point&, const Point&) const;

        // Attributes
        Real& x();
        Real x() const;

        Real& y();
        Real y() const;

        Real& z();
        Real z() const;

        // Operator functions
        Point& operator+=(Real);
        Point& operator+=(const Point&);
        Point& operator-=(Real);
        Point& operator-=(const Point&);
        Point& operator*=(Real);
        Point& operator*=(const Point&);
        Point& operator/=(Real);
        Point& operator/=(const Point&);
        friend void operator>>(std::istream&, Point&);

    private:
        Real x_ = 0;
        Real y_ = 0;
        Real z_ = 0;

};

// Global operator functions
Point operator+(const Point& lhs, Real);
Point operator+(const Point& lhs, const Point& rhs);
Point operator-(const Point& lhs, const Point& rhs);
Point operator*(const Point& lhs, const Point& rhs);
Point operator/(const Point& lhs, const Point& rhs);
std::ostream& operator<<(std::ostream&, const Point&);
