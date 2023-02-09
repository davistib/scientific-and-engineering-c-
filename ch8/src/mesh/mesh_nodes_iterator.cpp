// Implementation of MeshNodesIterator class

#include "mesh.hpp"
#include "mesh_nodes_iterator.hpp"

// #####################################################################################################################

// Constructors ####################################################################################

MeshNodesIterator::MeshNodesIterator(const Mesh& mesh) :
    nodes_(mesh.nodes_),
    current_(mesh.nodes_.length() - 1) {}

// Iterator functions ##############################################################################

bool MeshNodesIterator::more() const {
    return current_ >= 0;
}

void MeshNodesIterator::next() {
    --current_;
}

const Node& MeshNodesIterator::current() const {
    return nodes_[current_];
}
