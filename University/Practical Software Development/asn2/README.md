# Instructions
See `asn2.pdf` for the instructions for the assignment.

# Makefile
The `Makefile` provides targets for creating the testing executable and running various SE tools.
   * `make testGUI` - creates the unit testing executable.
   * `make clean` - removes all of the generated files.
   * `make tests` - runs the test executable to perform testing.
   * `make memcheck` - runs `valgrind` to check for memory leaks.
   * `make coverage` - runs `gcov/lcov` to produce a testing coverage report.
   * `make static` - runs the static analysis checker.
   * `make style` - runs the style checker to see if code conforms to Google's C++ code style.
   * `make docs` - generate the project documentation using `doxygen`.

