Instructions
------------------
See `asn1.pdf` for the instructions for the assignment.

Key Files
------------------
These are the key files for the first assignment of CPSC 2720.

`lib/` - contains the static libraries that you will test in this assignment: 
   * `libgui-clean.a` - a static library containing bug-free implementation of the classes for checking that your unit tests are correct.
   * `libgui-bugs.a` - a static library containing the implementation of the classes that you will be testing in this assignment.

`include/` - contains the header files for the classes that you will test.

`test/` - contains an example test fixture to get you started.

`Makefile` - A Makefile for creating executables that use either the "clean" or "buggy" libraries.


Running Tests
----------------
To run the tests, execute the following:

`make test-clean` (runs the tests with the 'clean' library)

`make test-bugs` (runs the tests with the 'buggy' library)

The provided test suite will fail and you will see the following output:

```
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TestCoord
[ RUN      ] TestCoord.output
test/TestCoord.cpp:12: Failure
Failed
[  FAILED  ] TestCoord.output (0 ms)
[----------] 1 test from TestCoord (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 0 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] TestCoord.output

 1 FAILED TEST
```

Where to go from here
----------------
From here, you will create test suites and unit tests to test the provided libraries. 
The 'buggy' library contains bugs, so not all of your unit tests should pass.