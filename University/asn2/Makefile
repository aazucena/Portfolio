CXX=g++
CXXFLAGS = -std=c++0x -g -fprofile-arcs -ftest-coverage

LINKFLAGS = -lgtest

SRC_DIR = src

TEST_DIR = test
TEST_FILE_EMPTY_WINDOW = asciiWindow_empty.txt
TEST_FILE_WIDGETS_WINDOW = asciiWindow_widgets.txt

SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint.py

PROGRAM_TEST = testGUI

.PHONY: all
all: $(PROGRAM_TEST) memcheck coverage docs static style

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o $(TEST_SRC)/*.o *.gcov *.gcda *.gcno \
	$(COVERAGE_RESULTS) \
	$(PROGRAM_TEST) $(MEMCHECK_RESULTS) \
	$(COVERAGE_DIR) \
	$(TEST_FILE_WIDGETS_WINDOW) \
	$(TEST_FILE_EMPTY_WINDOW) \
	html obj bin

$(PROGRAM_TEST): $(TEST_DIR) $(SRC_DIR)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) \
	$(TEST_DIR)/*.cpp $(SRC_DIR)/*.cpp $(LINKFLAGS)

tests: $(PROGRAM_TEST)
	$(PROGRAM_TEST)
	diff -s $(TEST_FILE_EMPTY_WINDOW) test/output/ascii_empty_expected.txt
	diff -s $(TEST_FILE_WIDGETS_WINDOW) test/output/ascii_widgets_expected.txt

memcheck: $(PROGRAM_TEST)
	valgrind --tool=memcheck --leak-check=yes $(PROGRAM_TEST)

coverage: $(PROGRAM_TEST)
	$(PROGRAM_TEST)
	# Determine code coverage
	$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS)
	# Only show code coverage for the source code files (not library files)
	$(LCOV) --extract $(COVERAGE_RESULTS) "*/asn2/src/*" -o $(COVERAGE_RESULTS)
	#Generate the HTML reports
	genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR)
	#Remove all of the generated files from gcov
	rm -f *.gc*

static: ${SRC_DIR} ${TEST_DIR}
	${STATIC_ANALYSIS} --verbose --enable=all ${SRC_DIR} ${TEST_DIR} ${SRC_INCLUDE} --suppress=missingInclude

style: ${SRC_DIR} ${TEST_DIR} ${SRC_INCLUDE}
	${STYLE_CHECK} $(SRC_INCLUDE)/* ${SRC_DIR}/* ${TEST_DIR}/*

docs: ${SRC_INCLUDE}
	doxygen doxyfile

