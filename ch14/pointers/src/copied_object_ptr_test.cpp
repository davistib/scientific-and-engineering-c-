// Define unit tests for the CopiedObjectPtr smart pointer class

#include <iostream>
#include <array>

#include "catch2/catch.hpp"

#include "copied_object_ptr.hpp"

// #################################################################################################

// Helper functions ################################################################################

// A simple data type to use for testing
class Point {
public:
    Point() {}
    Point(double x, double y, double z) {
        data_[0] = x; data_[1] = y; data_[2] = z;
    };
    double& x() {return data_[0];}
    double& y() {return data_[1];}
    double& z() {return data_[2];}
private:
    std::array<double, 3> data_ = {0, 0, 0};
};

// Tests ###########################################################################################

TEST_CASE( "CopiedObjectPtr", "[]" ) {

    SECTION( "User types" ) {

        // Define value to compare to
        double val = 0;
        auto target = Approx(val).margin(1e-7);

        SECTION( "Default") {
            CopiedObjectPtr<Point> p;
            CHECK( p.is_null() );
        }

        SECTION( "From new") {
            CopiedObjectPtr<Point> p(new Point());
            CHECK( !p.is_null() );

            SECTION( "can be dereferenced" ) {
                CHECK( p->x() == target );
            }

            auto p_copy = p;
            CHECK( p_copy != p );
            CHECK( p_copy->x() == target );
        }

        SECTION( "On copy construct" ) {
            CopiedObjectPtr<Point> p1(new Point(0, 1, 2));
            auto p2(p1);

            SECTION( "Copies value, not pointer" ) {
                auto target = Approx(1.0).margin(1e-7);
                CHECK( p1->y() == target );
                CHECK( p2->y() == target );
                CHECK( p1 != p2 );

                // check address of each
                SECTION( "Release control" ) {
                    auto rp1 = p1.release_control();
                    auto rp2 = p2.release_control();
                    CHECK( rp1 != rp2 );
                }
            }
        }

        SECTION( "On copy assign" ) {
            CopiedObjectPtr<Point> p1(new Point(0, 1, 2));
            auto p2 = p1;

            SECTION( "Copies value, not pointer" ) {
                auto target = Approx(1.0).margin(1e-7);
                CHECK( p1->y() == target );
                CHECK( p2->y() == target );
                CHECK( p1 != p2 );

                // check address of each
                SECTION( "Release control" ) {
                    auto rp1 = p1.release_control();
                    auto rp2 = p2.release_control();
                    CHECK( rp1 != rp2 );
                }
            }
        }

    }
}
