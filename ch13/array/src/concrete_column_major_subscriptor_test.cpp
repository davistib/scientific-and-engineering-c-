// Define unit tests for the ConcreteColumnMajorProjectionSubscriptor template class

#include <iostream>

#include "../../../external/catch2/catch.hpp"

#include "concrete_column_major_subscriptor.hpp"

// #####################################################################################################################

// Tests ###########################################################################################

TEST_CASE( "Create a 1D column major subscriptor", "[]" ) {

    auto c = ConcreteColumnMajorSubscriptor(SubscriptArray<1>(5));

    auto subscript = SubscriptArray<1>(2);
    REQUIRE( c.offset(subscript) == subscript(0) );

}

TEST_CASE( "Create a 2D column major subscriptor", "[]" ) {

    auto c = ConcreteColumnMajorSubscriptor(SubscriptArray<2>(3, 4));

    auto subscript = SubscriptArray<2>(2, 0);
    REQUIRE( c.offset(subscript) == 2 );

    subscript = SubscriptArray<2>(5, 0);
    REQUIRE( c.offset(subscript) == 5 );  // Note array is only size 3

    subscript = SubscriptArray<2>(0, 1);
    REQUIRE( c.offset(subscript) == 5 );

}
