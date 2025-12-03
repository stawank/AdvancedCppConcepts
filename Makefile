
CPP = c++14
PROJECT ?= main
INCLUDE_DIR = lib/eigen-5.0.0/


all: main
	@

run: all
	./$(PROJECT).out


main: $(PROJECT).cpp
	g++ -std=$(CPP) -I$(INCLUDE_DIR)  $(PROJECT).cpp -o $(PROJECT).out
	./$(PROJECT).out


threading: $(PROJECT).cpp
	g++ -std=$(CPP) -pthread  $(PROJECT).cpp -o $(PROJECT).out
	./$(PROJECT).out

clean:
	@rm -rf *.txt *.out *.o main 
