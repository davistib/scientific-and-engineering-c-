// Define a basic three-dimensional line class

#include "../types.hpp"
#include "point.hpp"

// #####################################################################################################################

class Line {

    public:
        // Constructors
        Line(Point p1, Point p2); // not passing by const reference, but may want to later

        // Member functions
        Real distance(const Point& point) const;
        // Real intersect(Line line);

        // Attributes
        Point& p1();
        const Point& p1() const;
        Point& p2();
        const Point& p2() const;

    private:
        Point p1_;
        Point p2_;

};
