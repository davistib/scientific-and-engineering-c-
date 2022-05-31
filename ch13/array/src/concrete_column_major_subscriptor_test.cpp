// Define unit tests for the ConcreteColumnMajorProjectionSubscriptor template class

#include <iostream>

#include "../../../external/catch2/catch.hpp"

#include "concrete_column_major_subscriptor.hpp"

// #####################################################################################################################

// Tests ###########################################################################################

TEST_CASE( "Create a 1D column major subscriptor", "[]" ) {

    auto c = ConcreteColumnMajorSubscriptor(SubscriptArray<1>(5));

    SECTION( "Computes the offset" ) {
        auto subscript = SubscriptArray<1>(2);
        REQUIRE( c.offset(subscript) == subscript(0) );
        REQUIRE( c.offset(subscript) == 2 );
    }

    SECTION( "Computes the offset outside bounds" ) {
        auto subscript = SubscriptArray<1>(6);
        REQUIRE( c.offset(subscript) == subscript(0) );
        REQUIRE( c.offset(subscript) == 6 );
    }

}

TEST_CASE( "Create a 2D column major subscriptor", "[]" ) {

    auto c = ConcreteColumnMajorSubscriptor(SubscriptArray<2>(3, 4));

    auto subscript = SubscriptArray<2>(2, 0);
    REQUIRE( c.offset(subscript) == 2 );

    subscript = SubscriptArray<2>(5, 0);
    REQUIRE( c.offset(subscript) == 5 );  // Note array is only size 3

    subscript = SubscriptArray<2>(0, 1);
    REQUIRE( c.offset(subscript) == 3 );

    subscript = SubscriptArray<2>(2, 3);
    REQUIRE( c.offset(subscript) == 11 );

}
