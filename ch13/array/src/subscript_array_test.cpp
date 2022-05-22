// Define unit tests for the SubscriptArray template class

#include "../../../external/catch2/catch.hpp"

#include "subscript_array.hpp"

// #####################################################################################################################

// Helper functions ################################################################################

template <Dimension N>
auto test(const SubscriptArray<N>& s) {
    auto d = s(0) * 3;
    return d;
}

// Tests ###########################################################################################

TEST_CASE( "Create a empty 1D subscript array", "[]" ) {
    auto s = SubscriptArray<1>();
    // FIXME: should this be initialized to 0?

    SECTION( "can be reassigned" ) {
        s = SubscriptArray<1>(2);
        REQUIRE( s(0) == 2 );
    }
}

TEST_CASE( "Create a 1D subscript array", "[]" ) {
    auto s = SubscriptArray<1>(5);

    REQUIRE( s(0) == 5 );
    REQUIRE( s(5) == 5 );  // just a random accessor since only 1 dimension

    SECTION( "can be reassigned from int" ) {
        s = 2;
        REQUIRE( s(0) == 2 );

        s(0) = 4;
        REQUIRE( s(1) == 4 );
    }

    SECTION( "can be reassigned from SubscriptArray" ) {
        auto a = SubscriptArray<1>(3);
        s = a;
        CHECK( a(0) == 3 );
        CHECK( s(0) == 3 );

        SECTION( "does not copy by reference" ) {
            a = 4;
            CHECK( s(0) == 3 );
        }

    }

    SECTION( "has constant access" ) {
        test(s);
    }

}

TEST_CASE( "Create a 2D subscript array", "[]" ) {
    auto s = SubscriptArray<2>(3, 4);

    REQUIRE( s(0) == 3 );
    REQUIRE( s(1) == 4 );

    SECTION( "can be reassigned single dimension" ) {
        s = 2;
        REQUIRE( s(0) == 2 );
        REQUIRE( s(1) == 2 );
    }

    SECTION( "can be reassigned from SubscriptArray" ) {
        auto a = SubscriptArray<2>(1, 2);
        s = a;
        CHECK( a(0) == 1 );
        CHECK( s(0) == 1 );

        // Not sure why there is not copy assignment for a SubscriptArray?
        SECTION( "does not copy by reference" ) {
            a = 10;
            CHECK( a(0) == 10 );
            CHECK( s(0) == 1 );
        }

    }

    SECTION( "has constant access" ) {
        test(s);
    }

}
