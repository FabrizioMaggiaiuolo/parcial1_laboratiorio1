#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "validaciones.h"

#define ANIOACTUAL 2022
#define MESACTUAL 6
#define DIAACTUAL 17

int ValidarNombre(char nombre[])
{
	int index;
	index = 0;

	if(strlen(nombre)>50)
	{
		index = 1;
	}

	return index;
}

int ValidarAnio(int anio)
{

	int index;
	index = 0;

	if(anio<2000 || anio>2050)
	{
		index = 1;
	}

	return index;
}

int ValidarMes(int anio, int mes)
{

	int index;
	index = 0;
	if(mes<1 || mes > 12)
	{
		index = 1;
	}

	return index;
}

int ValidarDia(int anio, int mes,int dia)
{

	int index;
		index = 0;

		switch(mes)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(dia<1 || dia > 31)
			{
				index = 1;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(dia<1 || dia > 30)
			{
				index = 1;
			}
			break;
		case 2:
			if(dia<1 || dia > 28)
			{
				index = 1;
			}
			break;
		}

	return index;
}


int ValidarExistenciaConsulta(int idConsulta,sConsulta consultas[],int tamanio)
{
	int index;
	index = -1;

	for(int i = 0;i<tamanio;i++)
	{
		if(consultas[i].idConsulta == idConsulta)
		{
			index = i;
			break;
		}
	}
	if(index == -1)
	{
		printf("El id de la consulta no existe \n");
	}
	return index;
}

int ValidarExistenciaMedico(int idIngresado,sMedico medicos[],int tamanioMedicos)
{
	int index;
	index = -1;

	for(int i = 0;i<tamanioMedicos;i++)
	{
		if(medicos[i].idMedico == idIngresado)
		{
			index = i;
			break;
		}
	}

	return index;
}

int ValidarEstadoDeConsulta(int posicion,int estadoConsulta,sConsulta consultas[],int tamanio)
{

	if(consultas[posicion].estado == 1)
	{
		estadoConsulta = 1;
	}
	if(estadoConsulta == 0)
	{
		printf("La consulta con el id ingresado no esta disponible \n");
	}
	return estadoConsulta;
}

int ValidarIdMedico(int idMedico, sConsulta consultas[],int tamanio)
{
	int index;
	index = 1;

	for(int i = 0; i<tamanio; i++)
	{
		if(consultas[i].idMedico == idMedico)
		{
			index = 0;
			break;
		}
	}

	return index;
}

