// directivas de preprocesamiento (se ejecutan antes de compilar para dar ordenes previas)

#include<stdio.h>
#include<stdlib.h>

#define LIMIT 50

int main() {
	int a = LIMIT;
	int* b = &a;
	int c = *b;
	
	printf("Valor a: %d - Direccion memoria a: %p - sizeof b: %d \n Valor b: %d - Direccion memoria b: %p - sizeof b: %d \n Valor c: %d - Direccion memoria de c: %p - sizeof b: %d ", a,b, sizeof(a), *b, &b, sizeof(b), c, &c, sizeof(c));
	
	return 0;
	
}
