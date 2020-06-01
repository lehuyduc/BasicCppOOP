CPP=g++
CXXFLAGS=-W -Wall -pedantic -g

all: main

clean:
	@rm -f main *.o *~

main: main.o Vector.o Matrix.o
	$(CPP) -o main $^

main.o: main.cpp Vector.hpp Matrix.hpp
	@echo build $@
	$(CPP) $(CXXFLAGS) -c $<


Vector.o: Vector.cpp Vector.hpp 
	@echo build $@
	$(CPP) $(CXXFLAGS) -c $<

Matrix.o: Matrix.cpp Matrix.hpp 
	@echo build $@
	$(CPP) $(CXXFLAGS) -c $<
