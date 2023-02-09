project(
  'mesh',
  'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14']
)

src = files([
  'src/geometry/point.cpp',
  'src/geometry/line.cpp',
])

src += files([
  'src/mesh/node.cpp',
  'src/mesh/element.cpp',
  'src/mesh/mesh.cpp',
  'src/mesh/node_reader.cpp',
  'src/mesh/mesh_elements_iterator.cpp',
  'src/mesh/mesh_nodes_iterator.cpp',
  'src/mesh/element_nodes_iterator.cpp',
])

lib = static_library(
  'core',
  src,
  install : false,
  dependencies : [],
)

dep = declare_dependency(
  link_with: lib,
)

executable(
  'main',
  'main.cpp',
  install : true,
  dependencies : [dep],
)
