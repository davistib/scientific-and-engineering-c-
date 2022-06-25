// Define unit tests for the ConcreteColumnMajorArray2d template class

#include <iostream>

#include "../../../external/catch2/catch.hpp"

#include "concrete_column_major_array_2d.hpp"

// #####################################################################################################################

using dMatrix = ConcreteColumnMajorArray2d<double>;

// Tests ###########################################################################################

TEST_CASE( "Create a 2D column major array", "[]" ) {

    auto a = dMatrix(3, 4);
    // FIXME: This is not working because it cannot resolve the function call
    // FIXME: from the base class. I'm not sure why - need to read up
    a = 1.0;

    CHECK( a.dim() == 2 );
    CHECK( a.shape(0) == 3 );
    CHECK( a.shape(1) == 4 );
    CHECK( a.length() == 12 );

    for (Subscript j = 0; j < a.shape(1); j++) {
        for (Subscript i = 0; i < a.shape(0); i++) {
            CHECK( a(i, j) == 1.0 );
        }
    }

}
