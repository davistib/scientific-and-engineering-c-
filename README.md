# scientific-and-engineering-cpp

This repository contains source code from the text
_Scientific and Engineering C++: An Introduction with Advanced Techniques and Examples_ [[1]](#1).

I have only typed up _some_ examples from the book. Specifically, those which are "less trivial" and/or seemed like good practice.

This is some of my first code in C++, so it is probably not very good. Furthermore, the reference text is quite old (prior to ISO standard!).
The text still seems like still a good reference of basic C++ and even better of class structure and organization for object oriented code.
In some places, I have used more modern C++ concepts (e.g. some use of auto, etc). But in general, I've using the examples in the book as-is.
As such, the examples shouldn't be used for any real code. Many concepts/classes could be replaced entirely by constructs in the STL.

Just having some fun...getting outside of my python comfort zone.

### Build

All (most?) of the examples are compiled using meson/ninja. I'm still testing this out as well.

There should be a simple bash script `build.sh` that compiles the code based on the `meson.build` file. Steps to compile and run (assuming the main is is `main.cpp`) would be:
- `build.sh`
- build/main

### Testing

Most of the code is "tested" just using the `main.cpp` routine. Some examples _may_ have testing (using catch2) if I decide it is useful.

### References
<a id="1">[1]</a> 
Barton, John J., and Lee R. Nackman. 
Scientific and Engineering C++ an Introduction with Advanced Techniques and Examples. 
Addison-Wesley Longman Publishing Co., Inc., 1994.
