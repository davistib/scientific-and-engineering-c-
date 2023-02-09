// Define the MeshNodesIterator

#include "../containers/simple_array.hpp"
#include "node.hpp"

// #####################################################################################################################

// Forward declarations
class Mesh;

/**
 * @brief Provides an iterator over the Nodes of a Mesh
 *
 * Note this traverses the Mesh Nodes in reverse order
 */
class MeshNodesIterator {

    public:

        // Constructors
        MeshNodesIterator(const Mesh&);

        // Iterator functions
        bool more() const;
        void next();
        const Node& current() const;

    private:
        const SimpleArray<Node>& nodes_;
        int current_;
};
