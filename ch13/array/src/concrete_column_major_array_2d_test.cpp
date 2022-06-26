// Define unit tests for the ConcreteColumnMajorArray2d template class

#include <iostream>

#include "../../../external/catch2/catch.hpp"

#include "concrete_column_major_array_2d.hpp"

// #####################################################################################################################

using Array2d = ConcreteColumnMajorArray2d<double>;

// Tests ###########################################################################################

TEST_CASE( "Create a 2D column major array", "[]" ) {

    auto a = Array2d(3, 4);
    // FIXME: This is not working because it cannot resolve the function call
    // FIXME: from the base class. I'm not sure why - need to read up
    double value = 1.0;
    a = value;

    auto target = Approx(value).margin(1e-7);

    CHECK( a.dim() == 2 );
    CHECK( a.shape(0) == 3 );
    CHECK( a.shape(1) == 4 );
    CHECK( a.length() == 12 );

    for (Subscript j = 0; j < a.shape(1); j++) {
        for (Subscript i = 0; i < a.shape(0); i++) {
            CHECK( a(i, j) == target );
        }
    }

    auto b = a[1];
    b = 3.0;
    for (Subscript i = 0; i < a.shape(0); i++) {
        std::cout << "[ ";
        for (Subscript j = 0; j < a.shape(1); j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << "]" << std::endl;
    }


}
