INCLUDE = include/
SRC     = src/
OBJ     = obj/
BIN     = bin/

$(BIN)uso_pila_max :$(OBJ)uso_pila_max.o 
	g++ -o $(BIN)uso_pila_max $(OBJ)uso_pila_max.o $(OBJ)pila_max.o

$(OBJ)uso_pila_max.o : $(OBJ)pila_max_vd.o $(OBJ)pila_max_cola.o $(OBJ)pila_max.o
	g++ -c -o $(OBJ)uso_pila_max.o $(SRC)uso_pila_max.cpp -I$(INCLUDE)

$(OBJ)pila_max_vd.o : $(SRC)pila_max_vd.cpp 
	g++ -c -o $(OBJ)pila_max_vd.o $(SRC)pila_max_vd.cpp -I $(INCLUDE)

$(OBJ)pila_max_cola.o : $(SRC)pila_max_cola.cpp
	g++ -c -o $(OBJ)pila_max_cola.o $(SRC)pila_max_cola.cpp -I $(INCLUDE)

$(OBJ)pila_max.o : $(SRC)pila_max.cpp
	g++ -c -o $(OBJ)pila_max.o $(SRC)pila_max.cpp -I $(INCLUDE)
clean:
	rm $(OBJ)*.o
	rm $(BIN)*
documentacion :
	doxygen 
