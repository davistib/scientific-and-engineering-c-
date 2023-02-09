// Define the Mesh class

#include <iostream>

#include "../types.hpp"
#include "../containers/simple_array.hpp"
#include "node.hpp"
#include "element.hpp"

// #####################################################################################################################

// Forward declarations
class MeshElementsIterator;
class MeshNodesIterator;

class Mesh {

    public:
        // Iterators
        friend MeshElementsIterator;  // Iterator over elements of mesh
        friend MeshNodesIterator;  // Iterator over nodes of mesh

        friend NodeReader;  // reader for Nodes

        // Operators
        /**
         * @brief Read mesh from input stream
         *
         * @param std::istream Input stream
         * @param Mesh Reference to Mesh object
         *
         * @return Input stream
         */
        friend std::istream& operator>>(std::istream&, Mesh&);

        // Member functions
        /**
         * @brief Check elements against angle threshold
         *
         * @param angle_threshold Upper angle threshold in degrees
         *
         * @return Whether large angles were detected
         */
        bool check_element_angles(Real angle_threshold) const;

    private:
        SimpleArray<Node> nodes_;
        SimpleArray<Element> elements_;
};
