CXX = g++
CXXFLAGS= -std=c++11 -g -lpthread -lX11

all: testBST

testBST:bst.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.cc
	$(CXX) $(CXXFLAGS) $<

bst.o: bst.h

clean:
	rm -rf *.o *~ *% *# .#* *.bak *.temp

clean-all: clean
	rm -rf testBST


