# Directory that contains this project
APP = playlist
GTEST = test_$(APP)

# Compilation command and flags
CXX=g++
CXXVERSION= -std=c++11
CXXFLAGS= $(CXXVERSION) -g
LINKFLAGS = -lgtest -lpthread -lgmock

# Directories
SRC_DIR = src
GTEST_DIR = test
SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := tests

# default rule for compiling .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean up all files that should NOT be submitted
.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o $(GTEST_DIR)/output/*.dat \
	*.gcov *.gcda *.gcno *.orig ???*/*.orig \
	$(APP) $(COVERAGE_RESULTS) \
	$(GTEST) $(MEMCHECK_RESULTS) $(COVERAGE_DIR)  \
	$(DOXY_DIR)/html obj bin $(APP).exe $(GTEST).exe

$(GTEST): $(GTEST_DIR)
	$(CXX) $(CXXFLAGS) -o $(GTEST) $(INCLUDE) \
	$(GTEST_DIR)/*.cpp $(LINKFLAGS)

$(APP): $(SRC_DIR)
	$(CXX) $(CXXFLAGS) -o $(GTEST) $(INCLUDE) \
	$(SRC_DIR)/*.cpp

.PHONY: console
console: $(APP)

.PHONY: tests
tests: $(GTEST)
