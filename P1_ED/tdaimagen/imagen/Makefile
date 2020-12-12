main_imagen: main_imagen.o imagenES.o imagen.o 
	g++ -o main_imagen main_imagen.o imagen.o imagenES.o

imagenES.o: imagenES.cpp imagenES.h
	g++ -g -c -o imagenES.o -I. imagenES.cpp

imagen.o: imagen.cpp imagen.h imagenES.h
	g++ -g -c -o imagen.o -I. imagen.cpp

ej_marco.o : main_imagen.cpp
	g++ -g -c -o main_imagen.o -I. main_imagen.cpp

clean:
	rm *.o

documentacion :
	doxygen -s Doxyfile
