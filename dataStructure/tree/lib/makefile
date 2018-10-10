CXX=g++
CXXFLAGS=-g -std=c++11 -Wall
CFLAGS=-I. -lgtest -lpthread
DEPS=treeNode.h tree.h
OBJ=test.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) 

a.out: $(OBJ)
	$(CXX) $(CFLAGS) -o $@ $^ 