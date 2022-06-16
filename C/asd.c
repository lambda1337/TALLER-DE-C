/*
     typedef 
     ->
     scanf con caracteres de inspeccion de entrada
     getc
--------------------------
     fopen, fwrite, fread , fclose
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Datos
{
   int codigo ;
   char nombre[64] ;
}Datos;

void ingresarDatos(Datos *) ;
void escribirRegistro(Datos) ;
void leerRegistro(Datos * ) ;
void mostrarRegistro(Datos) ;

int main (void) 
{
   Datos miDat ;
   ingresarDatos(&miDat) ;
   escribirRegistro(miDat) ;
   leerRegistro(&miDat) ;
   mostrarRegistro(miDat);
   return(0);
}

void ingresarDatos(Datos * miDat)
{
    int ret ;
    do  // una forma de validar el tipo de dato ingresado, esta version es prolija en la salida en caso de ingreso no valido
    {
         printf("Ingrese codigo: ");
         ret = scanf(" %d",&miDat->codigo);
	 if (ret == 0 ) while(getc(stdin) != '\n');
    }
    while (ret == 0 );

   printf("Ingrese nombre: ");
   scanf(" %[^\n]",miDat->nombre);
}

void escribirRegistro(Datos miReg) 
{
  FILE * fd = fopen("Datos","wb");  // "wb" si el archivo existe perdemos su contenido y si no existe lo crea 
                                    // "ab" si el archivo existe se hacen append al final del archivo y si el archivo no existe lo crea
  if ( fd != NULL )
   {
     fwrite(&miReg,sizeof(miReg),1,fd); 
     fclose(fd);
   }
}

void leerRegistro(Datos * miReg) 
{
  FILE * fd = fopen("Datos","rb");
  if ( fd != NULL )
   {
     fread(miReg,sizeof(*miReg),1,fd); 
     printf("sizeof(miReg): %d\n",sizeof(miReg));   
     fclose(fd);
   }
}

void mostrarRegistro(Datos miReg) 
{
   printf("codigo: %d\n",miReg.codigo);
   printf("nombre: %s\n",miReg.nombre);
}

