objects = 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 drill
CPP = g++
CPPFLAGS = -std=c++11
all: $(objects)

$(objects): %: %.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

clean:
	rm $(objects)