// Define the Element class
#pragma once

#include <iostream>

#include "../types.hpp"
#include "../containers/simple_array.hpp"
#include "node.hpp"

// #####################################################################################################################

// Forward declarations
class ElementNodesIterator;
class NodeReader;

/**
 * @brief Element is a finite volume in a mesh
 *
 * An element consists (in part) of a series of Nodes. These nodes form the edges of the Element. We do not want the
 * Element to know about the specific mapping between node numbers and the Node type. This keeps the Element type
 * independent of the Node representation.
 */
class Element {

    public:
        // Iterators
        friend ElementNodesIterator;

        // Operators
        friend void operator>>(NodeReader&, Element&);
        friend std::ostream& operator<<(std::ostream&, const Element&);

        // Member functions
        Real max_angle() const;

    private:
        // Store array of pointer to nodes
        SimpleArray<Node*> nodes_;

};
