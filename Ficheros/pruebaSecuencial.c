#include "secuencial.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main() {
  int i, numReg;
  FILE *f;
  tipoAlumno reg;
  char dni[10];

  numReg = leeSecuencial("alumnos.dat");
  printf("Numero de Registros: %d \n\n\n", numReg);

  // B�squeda de registros
  f = fopen("alumnos.dat", "rb");

  strcpy(dni, "7389298"); // Registro con NRR 37

  i = buscaReg(f, &reg, dni);

  if (i < 0) { 
    printf("No existe alumno con dni %s\n", dni); 
  }
  else { 
    printf("Registro con NRR %d", i);   
    printf("\t %s %s %s %s %s\n\n", reg.dni, reg.nombre, reg.ape1, reg.ape2, reg.provincia);
  }

  strcpy(dni, "123456789"); // No existe

  i = buscaReg(f, &reg, dni);

  if (i < 0) {
    printf("\nNo existe alumno con dni %s\n", dni);
  }
  else { 
    printf("Registro con NRR %d", i);
  	printf("\t %s %s %s %s %s\n\n", reg.dni, reg.nombre, reg.ape1, reg.ape2, reg.provincia);
  }

  strcpy(reg.dni, "12345678");
  strcpy(reg.nombre, "PERSONA");
  strcpy(reg.ape1, "FALSA");
  strcpy(reg.ape2, "INVENTADA");
  strcpy(reg.provincia, "MADRID");

  i = insertaReg("alumnos.dat", &reg);

  if (i < 0) {
    printf("\nError introduciendo nueva entrada al fichero\n");
  }
  else { 
    printf("Nuevo alumno introducido al fichero: %d", i);
    printf("\t %s %s %s %s %s\n\n", reg.dni, reg.nombre, reg.ape1, reg.ape2, reg.provincia);
  }

  fclose(f);

  //Fin de B�squeda


}

int leeSecuencial(char *fichSecuencial) {

  FILE *pFile = fopen(fichSecuencial, "r");
  int n;
  tipoAlumno a;

  if(pFile == NULL) {
    printf("Error reading file.\n");
    return -1;
  }

  while(fread(&a, sizeof(tipoAlumno), 1 , pFile)) {
    
    printf("%d: %s  %s %s %s  %s\n", n + 1, a.dni, a.nombre, a.ape1, a.ape2, a.provincia );
    
    n++;

  }

  return n;
}

int buscaReg(FILE *f, tipoAlumno *reg, char *dni) {
  int n = 0;
  tipoAlumno a;

  while(fread(&a, sizeof(tipoAlumno), 1 , f)) {

    if(!strcmp(dni, a.dni)) {
      strcpy(reg->dni ,a.dni);
      strcpy(reg->nombre, a.nombre);
      strcpy(reg->ape1, a.ape1);
      strcpy(reg->ape2, a.ape2);
      strcpy(reg->provincia, a.provincia);
      return n;
    }

    n++;

  }

  return -1;

}

int insertaReg(char *fichSecuencial, tipoAlumno *reg) {
  FILE *pFile = fopen(fichSecuencial, "ab");
  int n = 0;
  tipoAlumno a;

  if(pFile == NULL) {
    printf("Error reading file.\n");
    return -1;
  }

  fwrite(reg, sizeof(tipoAlumno), 1, pFile);

  return n + 1;
}

