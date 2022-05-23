project(
  'array',
  'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20']
)

# executable(
#   'main',
#   'main.cpp',
#   install : true
# )

# Tests ############################################################################################

# TODO: compile as a static library and link to avoid recompilation

executable(
  'tests',
  'src/subscript_array_test.cpp',
  'src/concrete_array_shape_test.cpp',
  'src/concrete_column_major_subscriptor_test.cpp',
  'test.cpp',
  install : true,
)
