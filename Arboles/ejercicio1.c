#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

int main(void)
{ Arbol varArbol, Tmp;

/* Creación arbol ejemplo de las transparencias de recorridos */
  varArbol = creaNodo('A');
  varArbol->izq=creaNodo('B');
  varArbol->der = creaNodo('C');
  varArbol->izq->izq=creaNodo('D');
  varArbol->izq->der=creaNodo('E');
  varArbol->der->izq=creaNodo('F');
  varArbol->der->der=creaNodo('G');

/* Aplicación de recorridos al arbol ejemplo */

  printf("Recorrido en PRE_ORDEN: ");
  preOrden(varArbol);
  printf("\n");
  printf("Recorrido en ORDEN: ");
  enOrden(varArbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN: ");
  postOrden(varArbol);
  printf("\n");
  printf("Recorrido en AMPLITUD: ");
  amplitud(varArbol);
  printf("\n");

/* Comenzar a implementar y probar las funciones del ejercicio 2 ... y segunda parte del ejercicio 3 */
  printf("Altura: %d\n", altura(varArbol));
  printf("Numero de nodos: %d\n", numNodos(varArbol));

  printf("Sustituye %d por %d: %d\n", , ,sustituye(varArbol, A, X));
  printf("Numero de nodos hoja: %d\n", numNodosHoja(varArbol));
  printf("Numero de nodos internos: %d\n", numNodosInternos(varArbol));

  Tmp = buscarMax(varArbol);
  printf("Buscar max: %d\n", Tmp->info); //Not working

  Tmp = buscarMin(varArbol);
  printf("Buscar min: %d\n", Tmp->info);

  printf("Anula: %d\n", anula(varArbol));
  return 1;
}

