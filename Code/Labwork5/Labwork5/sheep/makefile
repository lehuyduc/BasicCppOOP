CPP=g++
CXXFLAGS=-W -Wall -pedantic -g

all: Sheep

clean:
	@rm -f Sheep *.o *~

Sheep: Sheep.o
	$(CPP) -o Sheep $^

Sheep.o: Sheep.cpp Circle.hpp Diamond.hpp Drawing.hpp Ellipse.hpp Graphic.hpp Rectangle.hpp
	@echo build $@
	$(CPP) $(CXXFLAGS) -c $<
