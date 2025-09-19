PROG = p02_strings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

SOURCES = cliente.cc alfabeto.cc cadena.cc lenguaje.cc
OBJECTS = $(SOURCES:.cc=.o)

all: $(PROG)

$(PROG): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(PROG) $(OBJECTS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)