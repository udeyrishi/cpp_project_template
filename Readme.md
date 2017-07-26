## cpp\_project\_template

A simple reusable C/C++ project template that uses CMake for building and [Catch](https://github.com/philsquared/Catch) for testing. For creating a new project based on this:

* Put all your source files in `src`.
* Put all your header files in `inc`. These will be available through the include path in the source files.
* Put all your Catch test files in `test`. Leave the included `test/inc/catch.hpp` and `test/runner.cpp` as-is.
* Use proper extensions for the C (.c and .h) and C++ (.cpp and .hpp) code so that the correct compilers can be used for compiling and linking.
* Configure the project name in the top part of `CMakeLists.txt`. This will be used for generating the output target file names.


A sample project is part of the repository for reference. Use the included `build.py` as a utility build script (use `-h` for help). It outputs the object and static library targets in `out/release/lib` (`out/debug/lib` if `-d` is used), and the test (any any other, if added) executables in `out/release/bin` (`out/debug/bin` if `-d` is used). 
