OBJETOS = Vertice.o Lado.o Grafo.o Funcionesauxiliares.o principal.o

CPPFLAGS = -c -g -Wall -ansi

INCLUDES = Grafo.hpp Lado.hpp	Vertice.hpp 

objetivo: principal.exe


#Opciones para NO depurar
ndebug: CPPFLAGS += -DNDEBUG 
ndebug: objetivo

#Para general a documentacion
doc: Doxyfile 
		doxygen



principal.exe: $(OBJETOS)
									g++ $(OBJETOS) -o principal.exe 	 

principal.o: principal.cpp funcionesauxiliares.hpp grafo.hpp $(INCLUDES)
								g++ $(CPPFLAGS) principal.cpp

funcionesauxiliares.o: funcionesauxiliares.cpp funcionesauxiliares.hpp  $(INCLUDES)
											g++ $(CPPFLAGS) funcionesauxiliares.cpp

grafo.o: 	grafo.cpp $(INCLUDES)
								g++ $(CPPFLAGS) grafo.cpp

lado.o: lado.cpp $(INCLUDES)
							g++ $(CPPFLAGS) lado.cpp

vertice.o: vertice.cpp vertice.hpp
							g++ $(CPPFLAGS) vertice.cpp

clean:
	rm -rf *~ $(OBJETOS)
