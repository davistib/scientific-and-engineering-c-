// Define unit tests for the ConcreteColumnMajorArray2d template class

#include <iostream>

#include "../../../external/catch2/catch.hpp"

#include "concrete_column_major_array_2d.hpp"

// #####################################################################################################################

using Array2d = ConcreteColumnMajorArray2d<double>;

// Tests ###########################################################################################

TEST_CASE( "Create a 2D column major array", "[]" ) {

    auto a = Array2d(3, 4);

    CHECK( a.dim() == 2 );
    CHECK( a.shape(0) == 3 );
    CHECK( a.shape(1) == 4 );
    CHECK( a.length() == 12 );

    SECTION("Assign to a scalar value") {
        double value = 1.0;
        a = value;

        auto target = Approx(value).margin(1e-7);

        for (Subscript j = 0; j < a.shape(1); j++) {
            for (Subscript i = 0; i < a.shape(0); i++) {
                CHECK( a(i, j) == target );
            }
        }
    }

    SECTION("Modify a row using projection") {
        Subscript row_index = 1;
        auto b = a[row_index];
        double value = 3.0;
        b = value;
        auto target = Approx(value).margin(1e-7);

        for (Subscript j = 0; j < a.shape(1); j++) {
            CHECK( a(row_index, j) == target );
            CHECK( a[row_index][j] == target );
        }

        SECTION("Use a projection like an array") {
            for (Subscript i = 0; i < b.shape(0); i++) {
                CHECK( b[i] == target );
            }
        }
    }

}
