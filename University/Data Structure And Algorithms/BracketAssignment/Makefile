CXX = g++
CXXFLAGS= -std=c++11 -g -lpthread -lX11

all: testBracket

testBracket:bracket.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.cc
	$(CXX) $(CXXFLAGS) $<

bracket.o: bracket.h

clean:
	rm -rf *.o *~ *% *# .#* *.bak *.temp

clean-all: clean
	rm -rf testBracket


