CPP=g++
CXXFLAGS=-W -Wall -pedantic -g

all: main

clean:
	@rm -f main *.o *~

main: main.o List.o PointList.o
	$(CPP) -o main $^

main.o: main.cpp Point.hpp PointList.hpp List.hpp
	@echo build $@
	$(CPP) $(CXXFLAGS) -c $<


PointList.o: PointList.cpp Point.hpp PointList.hpp List.hpp 
	@echo build $@
	$(CPP) $(CXXFLAGS) -c $<

List.o: List.cpp List.hpp 
	@echo build $@
	$(CPP) $(CXXFLAGS) -c $<
