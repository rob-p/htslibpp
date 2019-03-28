# htslibpp
A minimal modern C++ (>= C++14) wrapper around htslib.  _Note_: This is a "free time" project, so work here may advance slowly.  Contributions and pull requests are welcome!

## Goals
  * Performance : the overhead compared to plain htslib (calling the C functions from C++) should be minimal in both time & memory.
  * Ergonomics : where possible, without sacrificing performance, dealing with htslibpp types should be easy and intuitive.
