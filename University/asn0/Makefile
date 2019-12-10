CXX = g++
CXXFLAGS = -g

LINKFLAGS = -lgtest

SRC_DIR = src

TEST_DIR = test

SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint.py

PROGRAM_TEST = testCalc

.PHONY: all
all: $(PROGRAM_TEST) memcheck docs static style

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o $(TEST_SRC)/*.o \
	$(PROGRAM_TEST) $(MEMCHECK_RESULTS) \
	docs html obj bin

$(PROGRAM_TEST): $(TEST_DIR)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) \
	$(TEST_DIR)/*.cpp $(SRC_DIR)/*.cpp $(LINKFLAGS)
	$(PROGRAM_TEST)

memcheck: $(PROGRAM_TEST)
	valgrind --tool=memcheck --leak-check=yes $(PROGRAM_TEST)

static: ${SRC_DIR} ${TEST_DIR}
	${STATIC_ANALYSIS} --verbose --enable=all ${TEST_DIR} ${SRC_INCLUDE} --suppress=missingInclude

style: ${TEST_DIR} ${SRC_INCLUDE}
	${STYLE_CHECK} $(SRC_INCLUDE)/* ${TEST_DIR}/*

docs: ${SRC_INCLUDE}
	doxygen doxyfile
