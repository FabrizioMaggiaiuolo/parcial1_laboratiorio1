#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "inputs.h"

// INGRESAR DATOS

int GetInt(char mensaje[])
{
	int retorno;

	printf("%s\n",mensaje);
	scanf("%d",&retorno);

	return retorno;
}

float GetFloat(char mensaje[])
{
	float numeroIngresado;
	printf("%s \n",mensaje);
	scanf("%f",&numeroIngresado);

	return numeroIngresado;
}

char GetChar(char mensaje[])
{
	char charIngresado;
	printf("%s \n",mensaje);
	fflush(stdin);
	scanf("%c",&charIngresado);

	return charIngresado;
}

void GetString(char mensaje[],char copiar[])
{
	if(copiar != NULL)
	{
		char stringIngresado[50];
		printf("%s \n",mensaje);
		scanf("%s",stringIngresado);

		strcpy(copiar,stringIngresado);
	}
}

