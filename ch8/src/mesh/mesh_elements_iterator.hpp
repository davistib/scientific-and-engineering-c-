// Define the MeshElementsIterator

#include "../containers/simple_array.hpp"

// #####################################################################################################################

// Forward declarations
class Element;
class Mesh;

/**
 * @brief Provides an iterator over the elements of a Mesh
 *
 * Note this traverses the Mesh Elements in reverse order
 */
class MeshElementsIterator {

    public:

        // Constructors
        MeshElementsIterator(const Mesh&);

        // Iterator functions
        bool more() const;
        void next();
        const Element& current() const;

    private:
        const SimpleArray<Element>& elements_;
        int current_;
};
