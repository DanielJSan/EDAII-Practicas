#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p) {

	if(p == NULL) {
		return -1; //Pila inválida
	}
    
	*p = NULL;
    
	return 0; //Éxito
}

int pilaVacia(Pila *p) {

	if(p == NULL) {
		return -1; //Pila inválida
	}
	    
	if(*p == NULL) {
		return 1; //La pila está vacía
	}
	else {
		return 0; //La pila no está vacía
	}
}

int pilaInserta(Pila *p,tipoElemento elemento) {

	tipoCelda *temp;

	if(p == NULL) {
		return -1;//Pila inválida
	}
    
	if(NULL == (temp = malloc(sizeof(tipoCelda)))) {
		return -2; //Fallo asignando memoria
	}
	else {
		temp->elemento = elemento;
		temp->sig = *p;
		*p = temp;
	}
	
	return 0; //Éxito
}

tipoElemento pilaSuprime(Pila *p) {
	
	tipoCelda *aBorrar = *p;
	tipoElemento elem = aBorrar->elemento;
	
	if(p == NULL) {
		return -1; //Pila inválida
	}
	
	if(pilaVacia(p)) {
		return -2; //La pila ya está vacía
	}
	
	*p = aBorrar->sig;
	elem = aBorrar->elemento;
	
	free(aBorrar);
	
	return elem;
}
