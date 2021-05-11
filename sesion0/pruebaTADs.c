/*
 * pruebaTADs.c	Ejemplo de utilización de TADs: sintaxis, palíndromo y 
 *
 *  Created on: 07/02/2019
 *      Author: M J Polo
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pilas/pila.h"
#include "colas/cola.h"
#include "listas/lista.h"

int sintaxis(char * expresion);
int palindromo(char *expresion);
int purga(Lista *l);
void radixSort(Lista *lista,int numGrupos,int numCifras);
int main(void)
{
// 1. Prueba eqiuilibrio de símbolos (TAD pila)
  int i;
  char expresion[50] = "{{{{((())";
	// Modificar adecuadamente la función sintaxis para que pueda
	// comprobar que una expresión aritmetica es correcta!!
	// strcpy(expresion, "[a+(b-c)*3+5]");

  if (sintaxis(expresion))
     printf("Expresion %s OK\n", expresion);
  else
       printf("Expresion %s incorrecta\n",expresion);
  strcpy(expresion, "{()}");
  if (sintaxis(expresion))
     printf("Expresion %s OK\n", expresion);
  else
       printf("Expresion %s incorrecta\n",expresion);

// 2. Prueba Palindromo (TADs pila y cola)

  strcpy(expresion, "anulalaluzazulalaluna"); 
  if (palindromo(expresion))
     printf("Expresion: %s (SI es palindromo)\n", expresion);
  else
     printf("Expresion; %s (NO es palindromo)\n", expresion);

// 3. Prueba RadixSort (TAD lista)

  Lista miLista;
  creaVacia(&miLista);
  // Insertamos 100 elementos (con valores entre 0 y 999) 
  for (i=0;i<100;i++) 
      inserta(rand()%1000,fin(&miLista),&miLista);
  imprime(&miLista);
  radixSort(&miLista, 10, 3);
  imprime(&miLista);
  
}

// 1. Equilibrio de símbolos utilizando TAD Pila
//    Ojo que dependiendo de la representación puede
//    quedar memoria sin liberar!!!!
//    Modificar adecuadamente la función para que no ocurra!!
int sintaxis(char * expresion)
{ Pila miPila;
  char c1,c2,finExp='\0';
  int i=0;

  pilaCreaVacia(&miPila);
  c1=expresion[i];

  while (c1!=finExp)
  { if (c1 =='{' ||c1 =='[' ||c1 =='(' )
       pilaInserta(&miPila,c1);
    else { if (pilaVacia(&miPila)) return 0;
           else { c2 = pilaSuprime(&miPila);
		switch (c2) {
			case '{': if (c1 != '}') return 0;
				  break;
			case '(':if (c1 != ')') return 0;
				  break;
                	case '[':if (c1 != ']') return 0;
				  break;
                	default:break;
	  	}
	}
   }
   i++;
   c1=expresion[i];
  }
  if (!pilaVacia(&miPila))  return 0; 	// Ojo puede quedar memoria sin liberar!!
  else return 1;
}
// 2. Función que determina si una frase se lee igual 
//    de derecha a izquierda que de izquierda a derecha,
//    utilizando TAD Pila y TAD Cola

int palindromo(char *expresion) {
  Cola c;
  Pila p; 
  int i = 0;
  int palindromo = 1;

  pilaCreaVacia(&p);
  colaCreaVacia(&c);

  printf("\n%ld\n", strlen(expresion));

  for(i = 0; i < strlen(expresion); i++) {

    pilaInserta(&p, expresion[i]);
    printf("\nPila insertada %d", i);

    colaInserta(&c, expresion[i]);
    printf("\nCola insertada %d\n", i);

  }

  printf("\nInsercion terminada");
  //fflush(stdin);
  do {
    printf("\nComparacion %d\n", i);

    if(pilaSuprime(&p) != colaSuprime(&c)) {
      palindromo = 0;
      printf("\nNo es palindromo\n");
    }

    i--;

  } while(i > 1 || palindromo == 1);

  if(palindromo) {
    return 1;
  }
  else {
    return 0;
  }

}
// 3. Algortimo de ordenación RadixSort modificado utilizando el TAD Lista
void radixSort(Lista *lista,int numGrupos,int numCifras) {
  /*Lista ptGrupos[numGrupos - 1]; 	// Los dos vectores de grupos se sustituyen por un vector de TAD Lista
  Lista ptUltimos[numGrupos - 1];
  int cifra;

  for(cifra = 1; cifra < numCifras - 1; cifra++) {
    for(int k = 0; k < numGrupos - 1; k++) {
      ptGrupos[k] = NULL;s
      ptUltimos[k] = NULL
    }

  }
  distribuir(cifra, lista, ptGrupos, ptUltimos);
  concatenar(lista, ptGrupos, ptUltimos);*/ 
}

