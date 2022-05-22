// Define unit tests for the SubscriptArray template class

#include "../../../external/catch2/catch.hpp"

#include "concrete_array_shape.hpp"

// #####################################################################################################################

// Tests ###########################################################################################

TEST_CASE( "Create a concrete 1D array shape", "[]" ) {

    SECTION( "Create from default constructor" ) {
        auto s = ConcreteArrayShape<1>();

        CHECK( s.dim() == 1 );

        SECTION( "Sets shape" ) {
            auto a = SubscriptArray<1>(5);
            s.set_shape(a);

            CHECK( s.shape(0) == 5 );
            CHECK( s.length() == 5 );
        }
    }
}

TEST_CASE( "Create a concrete 2D array shape", "[]" ) {

    SECTION( "Create from SubscriptArray" ) {
        auto s = ConcreteArrayShape<2>(SubscriptArray<2>(3, 4));

        CHECK( s.dim() == 2 );
        CHECK( s.shape(0) == 3 );
        CHECK( s.shape(1) == 4 );
        CHECK( s.length() == 12 );

    }
}
