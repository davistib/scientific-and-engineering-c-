// Implementation for the Element class

#include "element.hpp"
#include "node_reader.hpp"
#include "element_nodes_iterator.hpp"

// #####################################################################################################################

// Member functions ################################################################################

Real Element::max_angle() const {
    Real max = 0.0;
    for (ElementNodesIterator nodes(*this); nodes.more(); nodes.next()) {
        Real angle = nodes.current().angle(nodes.cw(), nodes.ccw());
        if (angle > max) max = angle;
    }
    return max;
}

// Global functions ################################################################################

void operator>>(NodeReader& reader, Element& element) {
    int n_nodes_in_element = reader.get_size();
    element.nodes_.resize(n_nodes_in_element);
    for (int i = 0; i < n_nodes_in_element; i++) {
        element.nodes_[i] = reader.get_node();
    }
}

std::ostream& operator<<(std::ostream& os, const Element& element) {
    for (ElementNodesIterator nodes(element); nodes.more(); nodes.next()) {
        os << nodes.current() << ", ";
    }
    return os;
}
