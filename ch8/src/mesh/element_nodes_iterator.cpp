// Implementation of the ElementNodesIterator class

#include "element_nodes_iterator.hpp"
#include "element.hpp"

// #####################################################################################################################

// Constructors ####################################################################################

ElementNodesIterator::ElementNodesIterator(const Element& element) :
    p_nodes_(element.nodes_),
    current_(element.nodes_.length() - 1) {}

// Iterator functions ##############################################################################

bool ElementNodesIterator::more() const {
    return current_ >= 0;
}

void ElementNodesIterator::next() {
    --current_;
}

Node& ElementNodesIterator::current() const {
    return *p_nodes_[current_];
}

Node& ElementNodesIterator::ccw() const {
    return *p_nodes_[(current_ + 1) % p_nodes_.length()];
}

Node& ElementNodesIterator::cw() const {
    int num_nodes = p_nodes_.length();
    // make sure index is always positive, so offset by num_nodes
    return *p_nodes_[(current_ + num_nodes - 1) % num_nodes];
}
