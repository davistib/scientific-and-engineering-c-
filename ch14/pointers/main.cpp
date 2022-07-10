#include <iostream>
#include <array>

#include "copied_built_in_ptr.hpp"
#include "copied_object_ptr.hpp"

class Point {
public:
    Point(double x, double y, double z) {data_[0] = x; data_[1] = y; data_[2] = z;};
    double& x() {return data_[0];}
    double& y() {return data_[1];}
    double& z() {return data_[2];}
private:
    std::array<double, 3> data_ = {0, 0, 0};
};

class PODStub {
public:
    PODStub(double data) : data_(data) {}
    // return reference to data, not a copy
    const double& get_data() const {return data_;}

private:
    double data_ = 0.0;
};

int main()
{
    std::cout << "Testing!" << std::endl;

    // create a new object
    CopiedBuiltInPtr<double> p1(new double(1));
    std::cout << *p1 << std::endl;

    CopiedBuiltInPtr<Point> p2(new Point(1, 2, 3));
    std::cout << (*p2).x() << std::endl;
    std::cout << (*p2).y() << std::endl;
    std::cout << (*p2).z() << std::endl;

    CopiedObjectPtr<Point> p3(new Point(1, 2, 3));
    std::cout << "(" << p3->x() << ", " << p3->y() << ", " << p3->z() << ")" << std::endl;

    // CopiedObjectPtr<Point> pt = p2;

    // This illustrates how resources are copied
    CopiedBuiltInPtr<PODStub> pod1(new PODStub(1));
    auto pod2 = pod1;
    std::cout << &(*pod1).get_data() << std::endl;
    std::cout << &(*pod2).get_data() << std::endl;

    // This illustrates how resources are not copied with built-in pointers
    auto* rawp1 = new PODStub(2);
    auto* rawp2 = rawp1;
    std::cout << &(*rawp1).get_data() << std::endl;
    std::cout << &(*rawp2).get_data() << std::endl;
    // this is a problem! may error or be nonsense
    delete rawp1;
    std::cout << (*rawp2).get_data() << std::endl;

    return 0;
}
