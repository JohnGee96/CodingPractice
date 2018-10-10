CXX=g++
CXXFLAGS=-g -std=c++11 -Wall
CFLAGS=-I. -lgtest -lpthread
DEPS=linkedList.h linkedListNode.h
OBJ=test.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $< $(CXXFLAGS) 

a.out: $(OBJ)
	$(CXX) $(CFLAGS) -o $@ $^ 
