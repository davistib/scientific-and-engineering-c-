// Define unit tests for ReferenceCount class

#include "catch2/catch.hpp"

#include "reference_count.hpp"

// #####################################################################################################################

// Tests ###########################################################################################

TEST_CASE( "ReferenceCount", "[]" ) {

    SECTION( "Default constructor" ) {
        ReferenceCount ref;
        CHECK( ref.unique() );
        CHECK( ref.count() == 1 );
    }

    SECTION( "Copy constructor" ) {
        ReferenceCount ref1;
        auto ref2(ref1);
        CHECK( !ref1.unique() );
        CHECK( !ref2.unique() );
        CHECK( ref1.count() == 2 );
        CHECK( ref1.count() == ref2.count() );
    }

    SECTION( "Copy assignment" ) {
        ReferenceCount ref1;
        auto ref2 = ref1;
        auto ref3 = ref1;
        CHECK( ref1.count() == 3 );
        CHECK( ref1.count() == ref3.count() );

        SECTION( "Assigning to a referenced counter" ) {
            ref1 = ref3;
            // Should not increment
            CHECK( ref1.count() == 3 );
            CHECK( ref3.count() == 3 );
        }
    }

    SECTION( "Destructor decrements and destroys" ) {
        ReferenceCount ref1;
        {
            auto ref2 = ref1;
            CHECK( ref1.count() == 2 );
        }
        CHECK( ref1.count() == 1 );
    }

}
