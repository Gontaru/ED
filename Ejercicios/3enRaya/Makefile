INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g


all: $(BIN)/Juego3enRaya

$(BIN)/Juego3enRaya : $(OBJ)/main.o $(OBJ)/ReglasJuego.o $(OBJ)/Tablero.o $(OBJ)/Jugador.o $(OBJ)/Ficha.o
	$(CXX) -o $(BIN)/Juego3enRaya $(OBJ)/main.o $(OBJ)/ReglasJuego.o $(OBJ)/Tablero.o $(OBJ)/Jugador.o $(OBJ)/Ficha.o

$(OBJ)/main.o : $(INC)/ReglasJuego.h $(SRC)/main.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/ReglasJuego.o : $(INC)/ReglasJuego.h $(INC)/Tablero.h $(INC)/Jugador.h $(SRC)/ReglasJuego.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/ReglasJuego.o $(SRC)/ReglasJuego.cpp

$(OBJ)/Tablero.o : $(INC)/Tablero.h $(SRC)/Tablero.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Tablero.o $(SRC)/Tablero.cpp

$(OBJ)/Jugador.o : $(INC)/Jugador.h $(INC)/Ficha.h $(SRC)/Jugador.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Jugador.o $(SRC)/Jugador.cpp

$(OBJ)/Ficha.o : $(INC)/Ficha.h $(SRC)/Ficha.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Ficha.o $(SRC)/Ficha.cpp	

clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*

