CXX = g++ # Compiler
CXXFLAGS = -c# Flags: g enables debugging
TARGET = xdiff # Executable

$(TARGET): main.o diff.o utils.o
	$(CXX) -o $(TARGET) main.o diff.o utils.o && make clean-obj

test: test.o diff.o utils.o
	$(CXX) -o xdiff_test test.o diff.o utils.o && make clean-obj

run_test: test
	./xdiff_test

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main.o

test.o: test.cpp
		$(CXX) $(CXXFLAGS) test.cpp -o test.o

diff.o: diff.cpp
	$(CXX) $(CXXFLAGS) diff.cpp -o diff.o

utils.o: utils.cpp
	$(CXX) $(CXXFLAGS) utils.cpp -o utils.o

clean-obj:
	rm *.o

clean:
	rm *.o *~ xdiff xdiff_test
