#include "dispersion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH(input) ((input) % CUBOS)
#define OFFSET(input) ((input) % CUBOS)
// Crea un fichero hash inicialmente vacio seg�n los criterios especificados en la pr�ctica
// Primera tarea a realizar para  crear un fichero organizado mediante DISPERSI�N
void creaHvacio(char *fichHash) {
  FILE *fHash;
  tipoCubo cubo;
  int j;
  int numCubos = CUBOS + CUBOSDESBORDE;

  memset(&cubo, 0, sizeof(cubo));

  fHash = fopen(fichHash, "wb");
  for (j = 0 ; j < numCubos ; j++) fwrite(&cubo, sizeof(cubo), 1, fHash);
  
  fclose(fHash);
}
// Lee el contenido del fichero hash organizado mediante el m�todo de DISPERSI�N seg�n los criterios
// especificados en la pr�ctica. Se leen todos los cubos completos tengan registros asignados o no. La
// salida que produce esta funci�n permite visualizar el m�todo de DISPERSI�N

int leeHash(char *fichHash) { 
  FILE *f;
  tipoCubo cubo;
  int j, i = 0;
  size_t numLee;

  f = fopen(fichHash,"rb");
  rewind(f);
  fread(&cubo, sizeof(cubo), 1, f);

  while (!feof(f)) {

  	for (j = 0; j < C ; j++) {

          if (j == 0) { 
            printf("Cubo %2d (%2d reg. ASIGNADOS)",i,cubo.numRegAsignados);
          }
          else {
            printf("\t\t\t");
          }
          if (j < cubo.numRegAsignados) {
  		    printf("\t%s %s %s %s %s\n", cubo.reg[j].dni, cubo.reg[j].nombre, cubo.reg[j].ape1, cubo.reg[j].ape2, cubo.reg[j].provincia);
          }
          else { printf ("\n"); }
    }

       i++;
       fread(&cubo, sizeof(cubo), 1, f);

   }

   fclose(f);
   return i;

}

int creaHash(char *fichEntrada, char *fichHash) {
  int nDesborde = 0;
  tipoCubo c;
  tipoAlumno a;

  FILE *fInput;
  FILE *fHash;

  if((fInput = fopen(fichEntrada, "r")) == NULL || (fHash = fopen(fichHash, "ab")) == NULL) {
    return -1;
  }

  creaHvacio(fichHash);

  while(fread(&a, sizeof(tipoAlumno), 1 , fichEntrada)) {
    fseek(fichHash, HASH() , SEEK_SET);
    fread(&c, sizeof(tipoCubo), 1, fichHash)

    c.numRegAsignados++;

    if(c.numRegAsignados > C) { //Hay desborde, asignamos los registros a los cubos de esta zona
      fseek(fSalida, sizeof(tipoCubo) * CUBOS, SEEK_SET);

      nDesborde++;
    }
  }


  return nDesborde; 
}

int buscaReg(FILE *fHash, tipoAlumno *reg, char *dni) { //No hay que abrir files aqui

}

int insertarReg(FILE *f, tipoAlumno *reg) {

} 