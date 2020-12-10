# Directory that contains this project
APP = contactBook

# Compilation command and flags
CXX=g++
CXXVERSION= -std=c++11
CXXFLAGS= $(CXXVERSION) -g

# Directories
SRC_DIR = src
SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := run

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean up all files that should NOT be submitted
.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o *.orig ???*/*.orig \
	$(APP) $(APP).exe

# compilation using the files in include, src, and src/project, but not test
compileApplication: $(SRC_DIR)
	$(CXX) $(CXXVERSION) -o $(APP) $(INCLUDE) $(SRC_DIR)/*.cpp

run: compileApplication
	./$(APP)
