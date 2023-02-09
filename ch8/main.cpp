// Main routine for testing

#include <iostream>
#include <fstream>

#include "src/geometry/point.hpp"
#include "src/types.hpp"
#include "src/mesh/mesh.hpp"
#include "src/mesh/mesh_nodes_iterator.hpp"

// #####################################################################################################################

void display_nodes(const Mesh&);

int main() {

    std::string mesh_file = "mesh.in";
    std::fstream fid;
    fid.open(mesh_file);
    if (!fid) {
        std::cerr << "Unable to open mesh file: " << mesh_file;
        std::exit(1);
    }

    Mesh mesh;
    fid >> mesh;

    display_nodes(mesh);

    Real angle_threshold = 90;
    bool valid = mesh.check_element_angles(angle_threshold);
    std::cout << valid << std::endl;

    return 0;
}

void display_nodes(const Mesh& mesh) {
    for (MeshNodesIterator nodes(mesh); nodes.more(); nodes.next()) {
        std::cout << nodes.current() << std::endl;
    }
}
