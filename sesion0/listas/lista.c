#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"
//Daniel Juanes Sánchez - 2ºTA2 Ingeniería Informática - danieljsan@usal.es
//DNI: 70919872Q

//----------------------------------------------------------------------------------------------
int creaVacia(Lista *l) {
    if (l == NULL) {
        return -2;
    }
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda)))) { //Queremos que l->raiz y l->ultimo apunten a una lista sin nodo, por lo que igualamos todo a lo que devuelve el malloc
        return -1;
    }
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}


//----------------------------------------------------------------------------------------------
int vacia(Lista *l) {
    if (l == NULL || l->raiz == NULL) { //La lista está mal inicializada
        return -1;
    }
    else if (l->raiz->sig == NULL) { //La lista está vacía
        return 1;
    }
    else { //La lista no está vacía
	return 0;
    }
}


//----------------------------------------------------------------------------------------------
int destruye(Lista *l) {
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig != NULL) {
        return -2;
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}


//----------------------------------------------------------------------------------------------
void imprime(Lista *l) {
    tipoCelda *aImprimir;
    int posicion;
    
    if (l == NULL || l->raiz == NULL) {
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        
        while (aImprimir != NULL) {
            printf("\nValor: %d en posición: %d",aImprimir->elemento, posicion++);
            aImprimir = aImprimir->sig;
        }
        printf("\n%d valores en la lista\n",posicion-1);
    }
}


//----------------------------------------------------------------------------------------------
tipoPosicion anterior(tipoPosicion p, Lista *l) {
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->raiz) {
        return l->raiz;
    }
    else {
        anterior = l->raiz;
        
        while (anterior->sig != p) {
            anterior = anterior->sig;
        }
        
        return anterior;
        
    }
}


//----------------------------------------------------------------------------------------------
tipoPosicion primero(Lista *l) {
	if (l == NULL) {
		fprintf(stderr,"Fallo precondición lista no existente!\n");
		return NULL;
	}
	else if (l->raiz == NULL){
		fprintf(stderr,"Fallo precondición lista no inicializada!\n");
		return NULL;
	} 
	else {
		return l->raiz;
	}
}


//----------------------------------------------------------------------------------------------
tipoPosicion siguiente(tipoPosicion p,Lista *l) {
	if(l == NULL || l->raiz == NULL || p == NULL) {
		return NULL;
	}
	
	return p->sig;
}


//----------------------------------------------------------------------------------------------
tipoPosicion fin(Lista *l) {
	if (l == NULL) {
		fprintf(stderr,"Fallo precondición lista no existente!\n");
		return NULL;
	}
	else if (l->ultimo == NULL){
		fprintf(stderr,"Fallo precondición lista no existente!\n");
		return NULL;
	} 
	else {
		return l->ultimo;
	}
}



//----------------------------------------------------------------------------------------------
int inserta(tipoElemento x, tipoPosicion p, Lista *l) {
	tipoCelda *nuevo;
    
	if (l == NULL) {
		fprintf(stderr,"Fallo precondición lista no existente!\n");
		return -1;
	}
	else if (l->raiz == NULL) {
		fprintf(stderr,"Fallo precondición nodo ficticio no existente!\n");
		return -2;
	}
	else if (p == NULL){
		fprintf(stderr,"Fallo precondición posición no válida!\n");
		return -3;
	}
	else if (NULL == (nuevo = (tipoCelda*)malloc(sizeof(tipoCelda)))) {
		fprintf(stderr,"Fallo reserva memoria!\n");
		return -4;
	}
	else {
		nuevo->elemento = x;
		nuevo->sig = p->sig;
		p->sig = nuevo;
		
		if (p == l->ultimo) {
		    l->ultimo = nuevo;
		}
		
		return 0;
	}
}


//----------------------------------------------------------------------------------------------
int suprime (tipoPosicion p, Lista *l) { //Not sure if it's working
	tipoPosicion tmp;
	
	if(vacia(l) == -1) {
		return -1; //Lista mal inicializada
	}
	else if(p == NULL) {
		return -2; //Posicion inválida
	}
	
	if(p == primero(l)) { //Si p es la primera posicion de la lista
		l->raiz = p->sig;

		free(p);

		return 0;
	}

	tmp = p->sig;
	p->sig = tmp->sig;
	
	if(p->sig == NULL) {
		l->ultimo = p;
	}
	
	free(tmp);

	return 0; //Éxito
}


//----------------------------------------------------------------------------------------------
tipoPosicion localiza (tipoElemento x, Lista *l) { //Esta función no puede devolver enteros por lo que se utiliza NULL como valor de reotrno de errores
	tipoPosicion q;

	if(vacia(l) == -1) {
		return NULL; //Lista mal inicializada
	}
	
	while(q->sig->elemento != x && q->sig != NULL) {
		if(q->sig == NULL) {
			return fin(l); //En caso de no encontrarse el elemento que se busca en la lista devuelve fin(l)
		}
		
		q = q->sig;
		
	}
	
	return q; //Éxito. Devuelve la posición en la que se encuentra por primera vez el elemento x en la lista l
}


//----------------------------------------------------------------------------------------------
int anula(Lista *l) {
    	tipoPosicion q, aBorrar;
    	
    	q = aBorrar = NULL;
    	
    	if(vacia(l) == -1) {
    		return -1; //Lista mal inicializada
    	}
    	if(vacia(l) == 0) {
    		return 0; //Ya está vacía
    	}
    	
    	q = l->raiz->sig;
	l->raiz->sig = NULL;
	
	while(q != NULL) { //Elimina todos los elementos hasta la última posición de la lista
		aBorrar = q;
		q = q->sig;
		
		if(aBorrar != NULL) {
			free(aBorrar);
		}
		
	}
	
	l->ultimo = primero(l);
	return 0; //Éxito
}


//----------------------------------------------------------------------------------------------
/*int concatena(Lista *lA, Lista *lB) {
	tipoPosicion inicioB, q;
	
	if(vacia(lA) == -1 || vacia(lB) == -1) {
		return -1; //Se recibe una lista mal inicializada
	}

	
	inicioB = primero(lB);
	q = inicioB->sig; 
	
	while(q != NULL) { //Inserción en orden de todos los elementos de B en A a partir de su último elemento
		inserta(q->elemento, fin(lA), lA);
		
		q = q->sig;
	
	
	}
	
	anula(lB); //Vaciado de lista B
	
	return 0; //Éxito
	
}*/

int concatena(Lista *lA, Lista *lB) {
	tipoPosicion finalA, inicioB, q;
	
	if(vacia(lA) == -1 || vacia(lB) == -1) {
		return -1; //Se recibe una lista mal inicializada
	}
	
	lA->ultimo->sig = lB->raiz->sig;
	lA->ultimo = lB->ultimo;
	lB->raiz->sig = NULL;
	lB->ultimo = lB->raiz;
	
	return 0; //Éxito
	
}

//----------------------------------------------------------------------------------------------
tipoElemento recupera(tipoPosicion p, Lista *l) {
	if(vacia(l) == -1) {
		return -1; //Se recibe una lista mal inicializada
	}
	if(p == NULL || p == fin(l)) {
		return -2; //Si la posición es inválida o se encuentra en el final de la lista
	}
	if(p->sig == NULL) {
		return -3; 		
	}

	return p->sig->elemento;
}






