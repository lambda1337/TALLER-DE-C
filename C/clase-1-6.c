// clase-1-6   
// Muestra por pantalla un menu de opciones que permiten
// 1  ingresar un texto por teclado                    
// 2  escribir el texto en un archivo    
// 3  leer el archivo
// 4  borrar el archivo            

#include <stdio.h>   
#include <string.h>  
#include <stdlib.h>  
#include <unistd.h>  

#define DIMENSION 64

// proto(tipos) de funciones
char * ingresoTexto(char *) ;       // Usa fgets para ingresar texto por teclado                    
int escriboTexto(char * , FILE *) ; // Usa fputs para escribir un texto en un archivo    
void leerTexto(char * , FILE *) ;   // Usa fgets para leer datos de un archivo
void borrarArchivo(char []) ;       // Usa unlink para borrar un archivo            
int menu(void) ;                    // Usa scanf para ingresar una opcion del menu            

//funcion principal
int main(void)
{
        int opcion ;
        char * texto ; 
        texto = (char *) malloc(DIMENSION); // malloc pide memoria dinamica
        if (texto == NULL )
          {
            printf("No hay memoria dinamica disponible \n") ;
            exit(-1);
          }
        while((opcion = menu()) != 0)
            {
              switch(opcion)
               {
                 case 1:
                    {
                     printf("Ingrese texto ---> ") ;
                     printf("direccion que retorna fgets %p \n", ingresoTexto(texto) );
                     printf("direccion del texto en memoria dinamica %p \n", texto );
                     printf("direccion de la variable texto en memoria estatica %p \n", &texto );
                     break;
                    }
                 case 2:
                    {
          	     FILE * fd = fopen("prueba","a");
                     if ( fd != NULL )
                     {
                        if (strlen(texto) > 0 && texto[0] != '\n')
                          {
                            printf("fputs retorno ---> %d \n",escriboTexto(texto,fd)) ;                    
                            memset(texto,0,DIMENSION);
                          }
                        else
           		   printf(" *** texto vacio \n") ;
                        fclose(fd) ;
		     }
                     else
          		printf(" *** ERROR fopen \n") ;
                     break ;
                    } 
                 case 3:
                    {
                     FILE * fd = fopen("prueba","r");
                     if ( fd != NULL )
                     {
                         char leido[2048] ;
                         memset(leido,0,2048);
                         leerTexto(leido,fd);
                         printf("fgets sobre prueba \n%s\n",leido) ;                    
                         fclose(fd) ;
		     }
                     else
         		printf(" *** ERROR fopen \n") ;
                     break ;
                    }
                 case 4:
                    {
                      borrarArchivo("prueba") ;                  
                    }
                 default : break ;
               }
            }
        free(texto); // libera la memoria dinamica solicitada con malloc                 
        return 0;
}

//definicion de funciones
char * ingresoTexto(char * texto)
{
      memset(texto,0,DIMENSION);
      return fgets(texto,DIMENSION,stdin);  // stdin es el teclado (stdin equivale a 0)
}

int escriboTexto(char * texto, FILE * fd) 
{
      return fputs(texto,fd);
}

void leerTexto(char leido[], FILE * fd) 
{
    char texto[DIMENSION] ;
    memset(texto,0,DIMENSION);
    while(fgets(texto,DIMENSION,fd) != NULL)
               strcat(leido,texto);
}

void borrarArchivo(char archivo[]) 
{
   unlink(archivo);
}

int menu(void)
{
   int opcion , ret ;
   printf(" **** Menu de Opciones **** \n");
   printf(" 1 - ingresar texto \n");
   printf(" 2 - escribir texto en el archivo\n");
   printf(" 3 - leer archivo \n");
   printf(" 4 - borrar archivo \n");
   printf(" 0 - salir \n");
   do  // una forma de validar el tipo de dato ingresado
    {
      printf(" ingrese opcion ---> ");
      ret = scanf("%d%*c",&opcion);
      printf("Si scanf retorna 1 (ingreso OK) si retorna 0 (ingreso ERROR) ---> %d\n",ret);
      __fpurge(stdin);
    }
   while (ret == 0 );
   return opcion;
}
