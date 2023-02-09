// Implementation of the Mesh class

#include "mesh.hpp"
#include "node_reader.hpp"
#include "mesh_elements_iterator.hpp"

// #####################################################################################################################

// Member functions ################################################################################

bool Mesh::check_element_angles(Real angle_threshold) const {
    bool valid = true;
    for (MeshElementsIterator elements(*this); elements.more(); elements.next()) {
        Real max_angle = elements.current().max_angle();
        if (max_angle > angle_threshold) {
            std::cout << "Element [" << elements.current() << "] has a large angle: " << max_angle << std::endl;
            valid = false;
        }
    }
    return valid;
}

// Global functions ################################################################################

std::istream& operator>>(std::istream& in, Mesh& mesh) {
    int n_nodes;
    int n_elements;
    in >> n_nodes;
    in >> n_elements;
    mesh.nodes_.resize(n_nodes);
    mesh.elements_.resize(n_elements);

    // Read nodes
    for (int inode = 0; inode < n_nodes; inode++) {
        // FIXME: write an input reader for Point class
        in >> mesh.nodes_[inode];
    }

    // Read elements
    NodeReader reader(mesh, in);
    for (int ielem = 0; ielem < n_elements; ielem++) {
        reader >> mesh.elements_[ielem];
    }

    return in;
}
