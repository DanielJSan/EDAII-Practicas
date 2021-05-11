# Proyecto para ejercicios sobre TADs

pruebaTADs: pruebaTADs.c pila.o cola.o lista.o
	gcc -g pruebaTADs.c pila.o cola.o lista.o -o pruebaTADs
pruebaLista: pruebaLista.c pila.o cola.o lista.o
	gcc -g pruebaLista.c pila.o cola.o lista.o -o pruebaLista
pila.o: pilas/pila.c pilas/pila.h
	gcc -g -c pilas/pila.c
cola.o: colas/cola.c colas/cola.h
	gcc -g -c colas/cola.c
lista.o: listas/lista.c listas/lista.h
	gcc -g -c listas/lista.c
limpiar:
	rm *.o

