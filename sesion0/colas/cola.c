#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"



int colaCreaVacia(Cola *c) {
    
    if(c == NULL) { 
    	return -1; //Cola inválida
    }
    
    c->frente = c->fondo = NULL;
    
    return 0; //Éxito
    
}

int colaVacia(Cola *c){
    
    if(c == NULL) {
    	return -1; //Cola inválida
    }
    
    if(c->frente == NULL && c->fondo == NULL) {
    	return 1; //Si el frente y el fondo son nulos, la cola está vacía
    }
    
    return 0; //La lista no está vacía

}

int colaInserta(Cola *c,tipoElemento elemento){

    tipoCelda *temp;
    
    if(c == NULL) {
    	return -1; //Cola inválida
    }
    
    
    
    if(NULL == (temp = malloc(sizeof(tipoCelda)))) {
    	return -2; //Fallo asignando memoria
    }
    
    temp->elemento = elemento;
    temp->sig = NULL;
    
    if(colaVacia(c)){
    	c->frente = c->fondo = temp;
    }
    else {
    	c->fondo = c->fondo->sig = temp;
    }
   
   return 0; //Éxito
    
}

tipoElemento colaSuprime(Cola *c){
    
    tipoCelda *aBorrar = c->frente;
    tipoElemento elem = aBorrar->elemento;
    
    if(c == NULL) {
    	return -1; //Cola inválida
    }
    
    if(colaVacia(c)) {
    	return -2; //La cola ya está vacía
    }
    
    c->frente = aBorrar->sig;
    
    if(aBorrar == c->fondo) {
    	c->fondo = c->frente;
    	
    	free(aBorrar);
    }
    
    return elem; //Éxito
}
