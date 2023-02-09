// Implementation for the NodeReader class

#include "mesh.hpp"
#include "node_reader.hpp"

// #####################################################################################################################

// Constructors ####################################################################################

NodeReader::NodeReader(Mesh& mesh, std::istream& in) :
    mesh_(mesh),
    in_(in) {
}

// Member functions ################################################################################

int NodeReader::get_size() {
    int size;
    in_ >> size;
    return size;
}

Node* NodeReader::get_node() {
    int inode;
    in_ >> inode;
    return &mesh_.nodes_[inode];
}
