#!/usr/bin/env bash
# Build and compile project

# Configure project manually, or with `meson init` to create the meson.build project file

[[ -d build ]] || mkdir build
meson build
ninja -C build
