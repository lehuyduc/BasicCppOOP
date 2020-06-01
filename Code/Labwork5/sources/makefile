CXX=g++
CXXFLAGS=-W -Wall -pedantic -std=c++11

ALL: constructeur-recopie derivation_patron limitations limites multiple1 \
	multiple2 multiple3 multiple4 operateur-affectation patronTU pointcol_int \
	surdef pointcol1

clean:
	@rm -f ${ALL} *.o *~

.cpp.o: 
	@echo building $@
	$(CXX) $(CXXFLAGS) -c $<

constructeur-recopie: constructeur-recopie.cpp
	@echo build $@
	$(CXX) $(CXXFLAGS) -o $@ $<
derivation_patron: derivation_patron.cpp
	@echo build $@
	$(CXX) $(CXXFLAGS) -o $@ $<
limitations: limitations.cpp
	@echo build $@
	$(CXX) $(CXXFLAGS) -o $@ $<
limites: limites.cpp
	@echo build $@
	$(CXX) $(CXXFLAGS) -o $@ $<
multiple1: multiple1.cpp
	@echo build $@
	$(CXX) $(CXXFLAGS) -o $@ $<
multiple2: multiple2.cpp
	@echo build $@
	$(CXX) $(CXXFLAGS) -o $@ $<
multiple3: multiple3.cpp
	@echo build $@
	$(CXX) $(CXXFLAGS) -o $@ $<
multiple4: multiple4.cpp
	@echo build $@
	$(CXX) $(CXXFLAGS) -o $@ $<
operateur-affectation: operateur-affectation.cpp
	@echo build $@
	$(CXX) $(CXXFLAGS) -o $@ $<
patronTU: patronTU.cpp
	@echo build $@
	$(CXX) $(CXXFLAGS) -o $@ $<
pointcol_int: pointcol_int.cpp
	@echo build $@
	$(CXX) $(CXXFLAGS) -o $@ $<
surdef: surdef.cpp
	@echo build $@
	$(CXX) $(CXXFLAGS) -o $@ $<
pointcol1: pointcol1.cpp
	@echo build $@
	$(CXX) $(CXXFLAGS) -o $@ $<
