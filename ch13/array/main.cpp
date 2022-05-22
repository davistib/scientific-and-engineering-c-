// Usage of the array library
// FIXME: this is just copied over for now - have not updated

#include <string>
#include <iostream>

#include "src/string_library.hpp"

// #####################################################################################################################

using namespace std::string_literals;

int main() {

    std::string lt = "this is not UPPERcase";
    auto ut{ string_library::to_upper(lt) };

    std::cout << "Before: " << lt << std::endl;
    std::cout << "After: " << ut << std::endl;

}
