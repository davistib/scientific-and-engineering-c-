// Define unit tests for the CopiedBuiltInPtr smart pointer class

#include <iostream>

#include "catch2/catch.hpp"

#include "copied_built_in_ptr.hpp"

// #################################################################################################

// Helper functions ################################################################################

template <class T>
auto pass_by_value(CopiedBuiltInPtr<T> p) {
    // this should return a copy of p
    return p;
}

template <class T>
T return_by_value(T& t) {
    // this should return a copy of whatever is created
    return t;
}

// Tests ###########################################################################################

TEST_CASE( "CopiedBuiltInPtr", "[]" ) {

    SECTION( "Built in types" ) {

        // Define value to compare to
        double val = 3;
        auto target = Approx(val).margin(1e-7);

        SECTION( "Default") {
            CopiedBuiltInPtr<double> p;
            CHECK( p.is_null() );
        }

        SECTION( "From new") {
            CopiedBuiltInPtr<double> p(new double(val));
            CHECK( !p.is_null() );

            SECTION( "can be dereferenced" ) {
                CHECK( *p == target );
            }
        }

        SECTION( "On copy construct" ) {
            CopiedBuiltInPtr<double> p1(new double(val));
            auto p2(p1);

            SECTION( "Copies value, not pointer" ) {
                CHECK( *p1 == target );
                CHECK( *p2 == target );
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
            CopiedBuiltInPtr<double> p1(new double(val));
            auto p2 = p1;

            SECTION( "Copies value, not pointer" ) {
                CHECK( *p1 == target );
                CHECK( *p2 == target );
                CHECK( p1 != p2 );

                // check address of each
                SECTION( "Release control" ) {
                    auto rp1 = p1.release_control();
                    auto rp2 = p2.release_control();
                    CHECK( rp1 != rp2 );
                }
            }
        }

        SECTION( "Function calls" ) {

            SECTION( "Performs copy on pass by value" ) {
                CopiedBuiltInPtr<double> p1(new double(val));
                auto copy_p1 = pass_by_value(p1);
                CHECK( *p1 == target );
                CHECK( *copy_p1 == target );
                CHECK( p1 != copy_p1 );
            }

            SECTION( "Performs copy on return by value" ) {
                CopiedBuiltInPtr<double> p1(new double(val));
                auto copy_p1 = return_by_value(p1);
                CHECK( *p1 == target );
                CHECK( *copy_p1 == target );
                CHECK( p1 != copy_p1 );
            }
        }

    }
}
