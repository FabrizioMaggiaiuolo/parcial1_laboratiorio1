#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

char* obtenerEspecialidad(sMedico medico, sEspecialidad especialidades[], int cantidadEspecialidades)
{
	int i;
	for(i= 0; i<cantidadEspecialidades; i++)
	{
		if(medico.idEspecialidad == especialidades[i].idEspecialidad)
		{
			break;
		}
	}
	return especialidades[i].descripcion;
}

char* obtenerDiagnostico(sConsulta consulta, sDiagnostico diagnosticos[])
{
	int i;

	for(i = 0; i<3; i++)
	{
		if(consulta.idDiagnostico == diagnosticos[i].idDiagnostico)
		{
			break;
		}
	}

	return diagnosticos[i].descripcion;
}

