// Define the NodeReader class

#include <iostream>

// #include "mesh.hpp"
#include "node.hpp"

// #####################################################################################################################

// Forward declaration
class Mesh;

class NodeReader {

    public:
        // Constructors ###########################################################################

        /**
         * @brief Create a new NodeReader from a mesh object and input stream
         *
         * @param Mesh a reference to a mesh
         * @param std::istream an input stream
         */
        NodeReader(Mesh&, std::istream&);

        // Member functions ########################################################################

        /**
         * @brief Read number of Nodes in current element
         *
         * @return Number of Nodes in current element
         */
        int get_size();

        /**
         * @brief
         *
         * @return
         */
        Node* get_node();

    private:
        Mesh& mesh_;
        std::istream& in_;
};
