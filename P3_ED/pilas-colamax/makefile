INCLUDE = include/
SRC     = src/
OBJ     = obj/
BIN     = bin/

$(BIN)uso_cola_max : $(OBJ)uso_cola_max.o 
	g++ -o $(BIN)uso_cola_max $(OBJ)uso_cola_max.o $(OBJ)cola_max.o

$(OBJ)uso_cola_max.o : $(OBJ)cola_max.o 
	g++ -c -o $(OBJ)uso_cola_max.o $(SRC)uso_cola_max.cpp -I$(INCLUDE)

$(OBJ)cola_max.o : $(SRC)cola_max.cpp
	g++ -c -o $(OBJ)cola_max.o $(SRC)cola_max.cpp -I$(INCLUDE)

clean:
	rm $(OBJ)*.o
	rm $(BIN)*
documentacion :
	doxygen 
