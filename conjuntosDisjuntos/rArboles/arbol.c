#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "cola.h"

//
// Reserva de memoria para un nuevo nodo de árbol binario
//
Arbol creaNodo(tipoInfo info)
{ tipoNodo * nuevo;

  //   nuevo =(tipoNodo *)calloc(1, sizeof(tipoNodo));
  if ((nuevo =(tipoNodo *)malloc(sizeof(tipoNodo)))==NULL)
	return NULL;
  else
  { 	nuevo->info=info;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	return nuevo;
   }
}

//
// Recorrido en amplitud o por niveles: necesita una cola de punteros a nodos de árbol binario!!!
//

void amplitud(Arbol raiz) { 
  Cola c;
  tipoNodo *nodo;

  colaCreaVacia(&c);

  nodo = raiz;

  if (raiz!=NULL) { colaInserta(&c,nodo); }


  while (!colaVacia(&c)) {
    nodo = (Arbol) colaSuprime(&c);

    printf("%c ", nodo->info);

    if (nodo->izq!=NULL) { colaInserta(&c,nodo->izq); }
    if (nodo->der!=NULL) { colaInserta(&c,nodo->der); }

  }
}
// 
// Recorridos en profundidad "recursivos"
//
void preOrden(Arbol raiz)
{ if (raiz!=NULL)
  { printf("%c ",raiz->info);
    preOrden(raiz->izq);
    preOrden(raiz->der);
  }
}
void enOrden(Arbol raiz)
{ if (raiz!=NULL)
  { enOrden(raiz->izq);
    printf("%c ",raiz->info);
    enOrden(raiz->der);
  }
}
void postOrden(Arbol raiz)
{ if (raiz!=NULL)
  { postOrden(raiz->izq);
    postOrden(raiz->der);
    printf("%c ",raiz->info);
  }
}

//ALGORITMOS


int altura(Arbol raiz) {
  int alturaD, alturaI;

  if(raiz != NULL) {
  	alturaI = altura(raiz->izq);
  	alturaD = altura(raiz->der);
  	
  	if(alturaI > alturaD) { return (alturaI + 1); }
	else { return (alturaD + 1); }
  }
  else { return -1; }
  
}

int numNodos(Arbol raiz) {  //DONE
  int nNodos = 1;

  if(raiz != NULL) {

    if (raiz->izq != NULL) { nNodos += numNodos(raiz->izq); }
    if (raiz->der != NULL) { nNodos += numNodos(raiz->der); }

  }
  
  return nNodos;
}

int numNodosHoja(Arbol raiz) { //DONE 
  int nNodos = 0;

  if(raiz->izq == NULL && raiz->der == NULL) { 
  	nNodos = 1; 
  }
  else {

    if (raiz->izq != NULL) { nNodos += numNodosHoja(raiz->izq); }
    if (raiz->der != NULL) { nNodos += numNodosHoja(raiz->der); }

  }
  
  return nNodos;
}

Arbol anula(Arbol raiz) {

}

int sustiuye(Arbol raiz, tipoInfo x, tipoInfo y) {
  if(raiz != NULL) {

  }
}



int numNodosInternos(Arbol raiz) { //DONE
  int nNodos = 0;

  if(raiz->izq != NULL && raiz->der != NULL) { 
    nNodos = 1; 
    
    if (raiz->izq != NULL) { nNodos += numNodosInternos(raiz->izq); }
    if (raiz->der != NULL) { nNodos += numNodosInternos(raiz->der); }

  }
  
  return nNodos;
}


int numHijoUnico(Arbol raiz) {

}

Arbol buscarMax(Arbol raiz) { //Not working
  Arbol Tmp;

  if(raiz != NULL) {

    if (raiz->izq != NULL) { 

      Tmp = buscarMax(raiz->izq);
      if(Tmp->info > raiz->info) { return Tmp; }

    }
    if (raiz->der != NULL) { 

      Tmp = buscarMax(raiz->der);
      if(Tmp->info > raiz->info) { return Tmp; }

    }

    
  }

  return raiz;
}

Arbol buscarMin(Arbol raiz) { //Not working
  Arbol Tmp;

  if(raiz != NULL) {

    if (raiz->izq != NULL) { 

      Tmp = buscarMin(raiz->izq);
      if(Tmp->info < raiz->info) { return Tmp; }

    }
    if (raiz->der != NULL) { 

      Tmp = buscarMin(raiz->der);
      if(Tmp->info < raiz->info) { return Tmp; }

    }

    return raiz;
  }
}

int similares(Arbol r1,Arbol r2) {

  if(r1 == NULL && r2 == NULL) {
    return 1;
  }

  if(r1 != NULL && r2 != NULL) {
    return (similares(r1->izq, r2->izq) && similares(r1->der, r2->der));
  }

  return 0;
}

int equivalentes(Arbol r1,Arbol r2) {
  if(r1 == NULL && r2 == NULL) {
    return 1;
  }

  if(r1 != NULL && r2 != NULL) {
    return (r1->info == r2->info && similares(r1->izq, r2->izq) && similares(r1->der, r2->der));
  }

  return 0;
}

Arbol especular(Arbol raiz) {

}

