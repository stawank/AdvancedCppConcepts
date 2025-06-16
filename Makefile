
CPP = c++11
PROJECT ?= main


all: main
	@

run: all
	./$(PROJECT).out


main: $(PROJECT).cpp
	g++ -std=$(CPP)  $(PROJECT).cpp -o $(PROJECT).out

threading: $(PROJECT).cpp
	g++ -std=$(CPP) -pthread  $(PROJECT).cpp -o $(PROJECT).out
	./$(PROJECT).out

clean:
	@rm -rf *.txt *.out *.o main 
