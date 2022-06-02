// Define unit tests for the ConcreteColumnMajorArray2d template class

#include <iostream>

#include "../../../external/catch2/catch.hpp"

#include "concrete_column_major_array_2d.hpp"

// #####################################################################################################################

// Tests ###########################################################################################

TEST_CASE( "Create a 2D column major array", "[]" ) {

    auto a = ConcreteColumnMajorArray2d<double>(3, 4);

    std::cout << a(0, 0);

}
