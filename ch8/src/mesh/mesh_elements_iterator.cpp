// Implementation of MeshElementsIterator class

#include "mesh.hpp"
#include "element.hpp"
#include "mesh_elements_iterator.hpp"

// #####################################################################################################################

// Constructors ####################################################################################

MeshElementsIterator::MeshElementsIterator(const Mesh& mesh) :
    elements_(mesh.elements_),
    current_(mesh.elements_.length() - 1) {}

// Iterator functions ##############################################################################

bool MeshElementsIterator::more() const {
    return current_ >= 0;
}

void MeshElementsIterator::next() {
    --current_;
}

const Element& MeshElementsIterator::current() const {
    return elements_[current_];
}
