// Define the ElementNodesIterator class

#include "../containers/simple_array.hpp"
#include "node.hpp"

// #####################################################################################################################

// Forward declaration
class Element;

/**
 * @brief An iterator over the Nodes in an Element
 */
class ElementNodesIterator {

    public:

        // Constructors
        ElementNodesIterator(const Element&);

        // Iterator functions
        bool more() const;
        void next();
        Node& current() const;

        // Neighbors of current iterate
        Node& ccw() const;
        Node& cw() const;

    private:
        const SimpleArray<Node*>& p_nodes_;
        int current_;
};
