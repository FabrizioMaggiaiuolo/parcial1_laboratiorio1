#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "funciones.h"
#include "validaciones.h"

#define GRIPEA 1
#define COVID19 2
#define PREINFARTO 3

//FUNCIONES

// ALTA DE CONSULTA
sConsulta cargarConsulta(sConsulta consultas[],int tamanio,int ids)
{
	sConsulta consultaAuxiliar;
	int index;
	index = 0;

	//nombre
	do
	{
	printf("Ingrese su nombre\n");
	scanf("%s",consultaAuxiliar.nombrePaciente);
	index = ValidarNombre(consultaAuxiliar.nombrePaciente);
	}while(index != 0);

	//fecha
	consultaAuxiliar = IngresoDeFecha(consultaAuxiliar);

	//inicialiazacion de datos
	consultaAuxiliar.estado = 1;
	consultaAuxiliar.idConsulta = ids;
	consultaAuxiliar.diagnostico.idDiagnostico = 0;

return consultaAuxiliar;
}

sConsulta IngresoDeFecha(sConsulta consultaAuxiliar)
{
	int index;

	do
	{
	consultaAuxiliar.fechaDeAtencion.anio = GetInt("Ingrese el año de la atencion");
	index = ValidarAnio(consultaAuxiliar.fechaDeAtencion.anio);
	}while(index != 0);
	do
	{
	consultaAuxiliar.fechaDeAtencion.mes = GetInt("Ingrese el mes de la atencion");
	index = ValidarMes(consultaAuxiliar.fechaDeAtencion.anio,consultaAuxiliar.fechaDeAtencion.mes);
	}while(index != 0);
	do
	{
	consultaAuxiliar.fechaDeAtencion.dia = GetInt("Ingrese el dia de la atencion");
	index = ValidarDia(consultaAuxiliar.fechaDeAtencion.anio,consultaAuxiliar.fechaDeAtencion.mes,consultaAuxiliar.fechaDeAtencion.dia);
	}while(index != 0);

	return consultaAuxiliar;
}


void AltaConsulta(sConsulta consultas[],int tamanio,int ids)
{
	int index;
	index = BuscarConsultaLibre(consultas,tamanio);
	if(index != -1)
	{
		consultas[index] = cargarConsulta(consultas,tamanio,ids);
	}

}

int BuscarConsultaLibre(sConsulta consultas[],int tamanio)
{
	int index;
	index = -1;

	for(int i = 0; i<tamanio;i++)
	{
		if(consultas[i].estado == 0)
		{
			index = i;
			break;
		}
	}

	return index;
}


// MODIFICACION CONSULTA


void MenuModificarConsulta(sConsulta consultas[],int tamanio)
{
	int respuesta;
	int idConsultaIngresada;
	int estadoConsulta;
	estadoConsulta = 0;
	idConsultaIngresada = -1;

	do
	{
		idConsultaIngresada = GetInt("Ingrese el id de la consulta");
		idConsultaIngresada = ValidarExistenciaConsulta(idConsultaIngresada,consultas,tamanio);
		estadoConsulta = ValidarEstadoDeConsulta(idConsultaIngresada,estadoConsulta,consultas,tamanio);
	} while(idConsultaIngresada == -1 || estadoConsulta == 0);

	printf("Ingrese una de las siguientes opciones para modificar: \n");
	printf("1. NOMBRE DEL PACIENTE \n");
	printf("2. FECHA DE CONSULTA \n");
	printf("3. MEDICO \n");
	respuesta = GetInt("Opcion que desea ingresar:");

	switch(respuesta)
	{
	case 1:
		ModificarNombrePaciente(idConsultaIngresada,consultas,tamanio);
		break;
	case 2:
		ModificarFecha(idConsultaIngresada,consultas,tamanio);
		break;
	case 3:
		ModificarMedico(idConsultaIngresada,consultas,tamanio);
		break;
	}
}

void ModificarNombrePaciente(int idConsultaIngresada,sConsulta consultas[],int tamanio)
{
	int index;
	char confirmar;

	sConsulta consultaAuxiliar;
	consultaAuxiliar = consultas[idConsultaIngresada];

	printf("El nombre del paciente actual para esta consulta: %s \n",consultas[idConsultaIngresada].nombrePaciente);
	do
	{
		printf("Ingrese el nombre por el cual quiere actualizar\n");
		scanf("%s",consultaAuxiliar.nombrePaciente);
		index = ValidarNombre(consultaAuxiliar.nombrePaciente);
	}while(index != 0);

	confirmar = GetChar("Esta seguro que quiere cambiar el nombre? S/N");
	if(confirmar == 's' || confirmar == 'S')
	{
		consultas[idConsultaIngresada] = consultaAuxiliar;
	}


}
void ModificarFecha(int idConsultaIngresada,sConsulta consultas[],int tamanio)
{
	char confirmar;

	sConsulta consultaAuxiliar;

	printf("La fecha actual de la consulta: %d/%d/%d \n",consultas[idConsultaIngresada].fechaDeAtencion.dia,consultas[idConsultaIngresada].fechaDeAtencion.mes,consultas[idConsultaIngresada].fechaDeAtencion.anio);

	consultaAuxiliar = IngresoDeFecha(consultas[idConsultaIngresada]);
	printf("La nueva fecha de la consulta: %d/%d/%d \n",consultaAuxiliar.fechaDeAtencion.dia,consultaAuxiliar.fechaDeAtencion.mes,consultaAuxiliar.fechaDeAtencion.anio);

	confirmar = GetChar("Esta seguro que quiere cambiar la fecha? S/N");
	if(confirmar == 's' || confirmar == 'S')
	{
		consultas[idConsultaIngresada] = consultaAuxiliar;
	}
}
void ModificarMedico(int idConsultaIngresada,sConsulta consultas[],int tamanio)
{
	int index;
	char confirmar;

	sConsulta consultaAuxiliar;

	printf("El id del medico actual es: %d",consultas[idConsultaIngresada].idMedico);

	do
	{
		consultaAuxiliar.idMedico = GetInt("Ingrese el id del medico por el cual quiere actualizar\n");
		index = ValidarIdMedico(consultaAuxiliar.idMedico, consultas,tamanio);
	}while(index != 0);

	confirmar = GetChar("Esta seguro que quiere cambiar el medico? S/N");
	if(confirmar == 's' || confirmar == 'S')
	{
		consultas[idConsultaIngresada] = consultaAuxiliar;
	}
}

// BAJA DE CONSULTA

void CancerlarConsulta(sConsulta consultas[],int tamanio)
{
	char confirmar;
	int idConsultaIngresada;
	int estadoConsulta;
	estadoConsulta = 0;
	idConsultaIngresada = -1;

	do
	{
		idConsultaIngresada = GetInt("Ingrese el id de la consulta");
		idConsultaIngresada = ValidarExistenciaConsulta(idConsultaIngresada,consultas,tamanio);
		estadoConsulta = ValidarEstadoDeConsulta(idConsultaIngresada,estadoConsulta,consultas,tamanio);

	} while(idConsultaIngresada == -1 || estadoConsulta == 0);

	confirmar = GetChar("Esta seguro que quiere dar de baja a la consulta? S/N");
	if(confirmar == 's' || confirmar == 'S')
	{
		consultas[idConsultaIngresada].estado = 0;
	}
}

// DIAGNOSTICAR

void Diagnosticar(sConsulta consultas[],int tamanio,sMedico medicos[],int tamanioMedicos)
{
	int idMedicoIngresado;
	int idConsultaDiagnostico;
	int diagnosticoIngresado;
	int posicionMedico;

	//verificar
	do
	{
		idMedicoIngresado = GetInt("Ingrese su id de medico");

	}while(ValidarExistenciaMedico(idMedicoIngresado,medicos,tamanioMedicos) == -1);

	for(int i = 0;i<tamanioMedicos;i++)
	{
		if(medicos[i].idMedico == idMedicoIngresado)
		{
			posicionMedico = i;
			break;
		}
	}


	printf("Ingrese el id de alguna de las siguientes consultas para diagnosticarla \n");
	for(int i = 0; i<tamanio; i++)
	{
		if(consultas[i].estado == 1)
		{
			if(consultas[i].diagnostico.idDiagnostico == 0)
			{
				printf("%d  %s \n",consultas[i].idConsulta,consultas[i].nombrePaciente);
			}
		}
	}
	idConsultaDiagnostico = GetInt("Consulta a diagnosticar:");

	printf("Ingrese alguno de los siguientes diagnosticos: \n");
	printf("1. Gripe A \n");
	printf("2. Covid-19 \n");
	printf("3. Pre infarto \n");
	diagnosticoIngresado = GetInt("Diagnostico seleccionado: ");

	int i;
	for( i = 0; i<tamanio; i++)
	{
		if(consultas[i].idConsulta == idConsultaDiagnostico)
		{
			consultas[i].idMedico = idMedicoIngresado;
			consultas[i].diagnostico.idDiagnostico = diagnosticoIngresado;
			switch(diagnosticoIngresado)
			{
			case 1:
				strcpy(consultas[i].diagnostico.descripcion, "Gripe A");
				break;
			case 2:
				strcpy(consultas[i].diagnostico.descripcion, "Covid-19");
				break;
			case 3:
				strcpy(consultas[i].diagnostico.descripcion, "Pre infarto");
				break;
			}
			medicos[posicionMedico].cantidadConsultas++;
			break;
		}
	}

}

// LISTAS

void MenuListar(sConsulta consultas[],int tamanio ,sMedico medicos[],int tamanioMedicos, sEspecialidad especialidades[],int tamanioEspecialidades, sHospital hospitales[], int tamaniohospitales)
{
	char opcion;

	printf("\n");
	printf("\n");

	printf("Elija una de las siguientes opciones: \n");
	printf("a. Todos los médicos.\n");
	printf("b. Todas las consultas.\n");
	printf("c. Todos los médicos con consultas diagnosticadas.\n");
	printf("d. Listado de consultas ordenadas por fecha, desde la más reciente hasta la más antigua.\n");
	printf("e. Listado de consultas que ya fueron diagnosticadas.\n");
	printf("f. Listado de las consultas diagnosticadas con covid-19 desde el inicio de la pandemia hasta la actualidad.\n");
	printf("g. Listado de consultas ordenadas por especialidad alfabéticamente.\n");
	printf("h. Listado de todas las consultas entre el mes de abril y julio para una especialidad determinada.\n");
	printf("i. Porcentaje de consultas diagnosticadas que atiende cada médico en función del total de diagnósticos.\n");
	printf("j. La enfermedad menos diagnositacada.\n");
	printf("k. La especialidad mas estudiada por los medicos.\n");
	printf("l. Mostrar hospitales y su cantidad de medicos.\n");
	printf("m. Mostrar las consultas de cada hospital.\n");
	printf("Opcion a elegir:  ");
	fflush(stdin);
	scanf("%c",&opcion);

	printf("\n");
	printf("\n");

	switch(opcion)
	{
	case 'a':
		ListarTodosMedicos(medicos,tamanioMedicos);
		break;
	case 'b':
		ListarTodasConsultas(consultas,tamanio);
		break;
	case 'c':
		ListarTodosMedicosConConsulta(consultas,tamanio,medicos,tamanioMedicos);
		break;
	case 'd':
		ConsultasPorFecha(consultas,tamanio);
		break;
	case 'e':
		ConsultasYaDiagnosticadas(consultas,tamanio);
		break;
	case 'f':
		CasosCovid19DesdeInicioDePandemia(consultas,tamanio,medicos,tamanioMedicos);
		break;
	case 'g':
		ConsultasOrdenadoEspecialidad(consultas,tamanio,medicos,tamanioMedicos);
		break;
	case 'h':
		ConsultasEntreMesesEspecialidad(consultas,tamanio,medicos,tamanioMedicos,4,7);
		break;
	case 'i':
		PorcentajeConsultasPorMedico(consultas,tamanio,medicos,tamanioMedicos);
		break;
	case 'j':
		EnfermedadMenosDiagnosticada(consultas,tamanio);
		break;
	case 'k':
		EspecialidadMasEstudiada(medicos,tamanioMedicos,especialidades,tamanioEspecialidades);
		break;
	case 'l':
		MostrarHospitalesYMedicos(hospitales,tamaniohospitales);
		break;
	case 'm':
		MostrarConsultasHospital(consultas,tamanio,medicos,tamanioMedicos,hospitales,tamaniohospitales);
		break;
	}

}

void ListarTodosMedicos(sMedico medicos[],int tamanioMedicos)
{
	for(int i = 0; i<tamanioMedicos;i++)
	{
		if(medicos[i].estado == 1)
		{
			printf("%-20s %s \n",medicos[i].nombre,medicos[i].especialidad.descripcion);
		}
	}
}

void ListarTodasConsultas(sConsulta consultas[],int tamanio)
{
	for(int i = 0; i<tamanio;i++)
	{
		if(consultas[i].estado == 1)
		{
			printf("%s %4d/%d/%d\n",consultas[i].nombrePaciente,consultas[i].fechaDeAtencion.dia,consultas[i].fechaDeAtencion.mes,consultas[i].fechaDeAtencion.anio);
		}
	}
}

void ListarTodosMedicosConConsulta(sConsulta consultas[],int tamanio,sMedico medicos[],int tamanioMedicos)
{
	for(int i = 0; i<tamanioMedicos;i++)
	{
		if(medicos[i].cantidadConsultas >0)
		{
			printf("%-20s %-20s \n",medicos[i].nombre,medicos[i].especialidad.descripcion);
			for(int j = 0;j<tamanio;j++)
			{
				if(medicos[i].idMedico == consultas[j].idMedico)
				{
					printf("%20s %4d/%d/%d %6s\n",consultas[j].nombrePaciente,consultas[j].fechaDeAtencion.dia,consultas[j].fechaDeAtencion.mes,consultas[j].fechaDeAtencion.anio,consultas[j].diagnostico.descripcion);
				}
			}
		}
	}
}

void ConsultasPorFecha(sConsulta consultas[],int tamanio)
{
	sConsulta consultaAuxiliar;

	for(int i = 0;i<tamanio-1;i++)
	{
		for(int j = i+1;j<tamanio;j++)
		{
			if(consultas[i].fechaDeAtencion.anio < consultas[j].fechaDeAtencion.anio)
			{
				consultaAuxiliar = consultas[i];
				consultas[i] = consultas[j];
				consultas[j] = consultaAuxiliar;
			}
			else
			{
				if(consultas[i].fechaDeAtencion.anio == consultas[j].fechaDeAtencion.anio)
				{
					if(consultas[i].fechaDeAtencion.mes > consultas[j].fechaDeAtencion.mes)
					{
						consultaAuxiliar = consultas[i];
						consultas[i] = consultas[j];
						consultas[j] = consultaAuxiliar;
					}
					else
					{
						if(consultas[i].fechaDeAtencion.mes == consultas[j].fechaDeAtencion.mes)
						{
							if(consultas[i].fechaDeAtencion.dia > consultas[j].fechaDeAtencion.dia)
							{
								consultaAuxiliar = consultas[i];
								consultas[i] = consultas[j];
								consultas[j] = consultaAuxiliar;
							}
						}
					}
				}
			}
		}
	}

	ListarTodasConsultas(consultas,tamanio);

}

void ConsultasYaDiagnosticadas(sConsulta consultas[],int tamanio)
{
	for(int i = 0; i<tamanio;i++)
	{
		if(consultas[i].estado == 1)
		{
			if(consultas[i].diagnostico.idDiagnostico != 0)
			{
				printf("%s %4d/%d/%d %4s\n",consultas[i].nombrePaciente,consultas[i].fechaDeAtencion.dia,consultas[i].fechaDeAtencion.mes,consultas[i].fechaDeAtencion.anio,consultas[i].diagnostico.descripcion);
			}
		}
	}
}

void CasosCovid19DesdeInicioDePandemia(sConsulta consultas[],int tamanio,sMedico medicos[],int tamanioMedicos)
{
	char especialidadIngresada[21];
	printf("Ingrese la especialdad \n");
	fflush(stdin);
	scanf("%s",especialidadIngresada);
	strcpy(especialidadIngresada,strlwr(especialidadIngresada));

	for(int i = 0; i<tamanio;i++)
	{
		if(consultas[i].estado == 1)
		{
			for(int j = 0; j<tamanioMedicos;j++)
			{
				if(consultas[i].idMedico == medicos[j].idMedico && strcmp(medicos[j].especialidad.descripcion,especialidadIngresada) == 0)
				{
					if(consultas[i].fechaDeAtencion.anio>2020)
					{
						printf("%s %4d/%d/%d %4s\n",consultas[i].nombrePaciente,consultas[i].fechaDeAtencion.dia,consultas[i].fechaDeAtencion.mes,consultas[i].fechaDeAtencion.anio,consultas[i].diagnostico.descripcion);
					}
					else
					{
						if(consultas[i].fechaDeAtencion.anio == 2020)
						{
							if(consultas[i].fechaDeAtencion.mes > 3)
							{
								printf("%s %4d/%d/%d %4s\n",consultas[i].nombrePaciente,consultas[i].fechaDeAtencion.dia,consultas[i].fechaDeAtencion.mes,consultas[i].fechaDeAtencion.anio,consultas[i].diagnostico.descripcion);
							}
							else
							{
								if(consultas[i].fechaDeAtencion.mes == 3)
								{
									if(consultas[i].fechaDeAtencion.dia > 2)
									{
										printf("%s %4d/%d/%d %4s\n",consultas[i].nombrePaciente,consultas[i].fechaDeAtencion.dia,consultas[i].fechaDeAtencion.mes,consultas[i].fechaDeAtencion.anio,consultas[i].diagnostico.descripcion);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void ConsultasOrdenadoEspecialidad(sConsulta consultas[],int tamanio,sMedico medicos[],int tamanioMedicos)
{
	sMedico medicoAuxiliar;

	for(int i = 0;i<tamanioMedicos-1;i++)
	{
		for(int j = i+1;j<tamanioMedicos;j++)
		{
			if(strcmp(medicos[i].especialidad.descripcion,medicos[j].especialidad.descripcion)>0)
			{
				medicoAuxiliar = medicos[i];
				medicos[i] = medicos[j];
				medicos[j] = medicoAuxiliar;
			}
		}
	}

	for(int i = 0;i<tamanioMedicos;i++)
	{
		for(int j = 0;j<tamanio;j++)
		{
			if(medicos[i].idMedico == consultas[j].idMedico)
			{
				printf("%s %10s %4d/%d/%d %4s\n",consultas[j].nombrePaciente,medicos[i].especialidad.descripcion,consultas[j].fechaDeAtencion.dia,consultas[j].fechaDeAtencion.mes,consultas[j].fechaDeAtencion.anio,consultas[j].diagnostico.descripcion);
			}
		}
	}
}


void ConsultasEntreMesesEspecialidad(sConsulta consultas[],int tamanio,sMedico medicos[],int tamanioMedicos,int mes1, int mes2)
{
	char especialidadIngresada[21];
	printf("Ingrese la especialdad \n");
	fflush(stdin);
	scanf("%s",especialidadIngresada);
	strcpy(especialidadIngresada,strlwr(especialidadIngresada));

	for(int i=0;i<tamanioMedicos;i++)
	{
		if(strcmp(medicos[i].especialidad.descripcion,especialidadIngresada)==0)
		{
			for(int j = 0;j<tamanio;j++)
			{
				if(medicos[i].idMedico == consultas[j].idMedico)
				{
					if(consultas[j].fechaDeAtencion.mes >= mes1 && consultas[j].fechaDeAtencion.mes <= mes2)
					{
						printf("%s %10s %4d/%d/%d %4s\n",consultas[j].nombrePaciente,medicos[i].especialidad.descripcion,consultas[j].fechaDeAtencion.dia,consultas[j].fechaDeAtencion.mes,consultas[j].fechaDeAtencion.anio,consultas[j].diagnostico.descripcion);
					}
				}
			}
		}
	}
}
void PorcentajeConsultasPorMedico(sConsulta consultas[],int tamanio,sMedico medicos[],int tamanioMedicos)
{
	int contadorTotal;
	contadorTotal = 0;
	int resultado;

	for(int i = 0;i<tamanio;i++)
	{
		if(consultas[i].estado == 1)
		{
			contadorTotal++;
		}
	}
	for(int i = 0;i<tamanioMedicos;i++)
	{
		resultado = 100*medicos[i].cantidadConsultas/contadorTotal;
		printf("%s tiene el %d porciento de las consultas\n",medicos[i].nombre,resultado);
	}
	printf("\n");

}

void EnfermedadMenosDiagnosticada(sConsulta consultas[],int tamanio)
{
	int contadorGripeA;
	contadorGripeA = 0;
	int contadorCovid19;
	contadorCovid19 = 0;
	int contadorPreInfarto;
	contadorPreInfarto = 0;

	for(int i = 0; i<tamanio;i++)
	{
		switch(consultas[i].diagnostico.idDiagnostico)
		{
		case 1:
			contadorGripeA++;
			break;
		case 2:
			contadorCovid19++;
			break;
		case 3:
			contadorPreInfarto++;
			break;
		}
	}

	if(contadorGripeA < contadorCovid19 && contadorGripeA < contadorPreInfarto)
	{
		printf("La enfermedad menos diagnosticada es: Gripe A\n");
	}
	else
	{
		if(contadorCovid19 < contadorGripeA && contadorCovid19 < contadorPreInfarto)
		{
			printf("La enfermedad menos diaagnosticada es: Covid-19\n");
		}
		else
		{
			if(contadorPreInfarto < contadorGripeA && contadorPreInfarto < contadorCovid19)
			{
				printf("La enfermedad menos diagnosticada es: Pre Infarto\n");
			}
			else
			{
				printf("Todas las enfermedades tiene  la misma cantidad de diagnosticos\n");
			}
		}
	}

}

void EspecialidadMasEstudiada(sMedico medicos[],int tamanioMedicos, sEspecialidad especialidades[],int tamanioEspecialidades)
{
	sEspecialidad especialidadMasEstudiada;
	int masEspecialidad;
	masEspecialidad = 0;
	int auxiliar;

	for(int i = 0 ; i < tamanioEspecialidades; i++)
	{
		auxiliar = 0;
		for(int j = 0; j<tamanioMedicos; j++)
		{
			if(medicos[j].especialidad.idEspecialidad == especialidades[i].idEspecialidad)
			{
				auxiliar++;
			}

		}

		if(masEspecialidad < auxiliar)
		{
			masEspecialidad = auxiliar;
			especialidadMasEstudiada = especialidades[i];
		}
	}
	printf("La especialidad mas estudiada es: %s\n",especialidadMasEstudiada.descripcion);
}

void MostrarHospitalesYMedicos(sHospital hospitales[], int tamaniohospitales)
{
	for(int i = 0; i< tamaniohospitales; i++)
	{
		printf("%-20s Cantidad de medicos:%d \n",hospitales[i].nombre,hospitales[i].cantidadDeMedicos);
	}
}

void MostrarConsultasHospital(sConsulta consultas[],int tamanio ,sMedico medicos[],int tamanioMedicos, sHospital hospitales[], int tamaniohospitales)
{
	for(int i = 0; i<tamaniohospitales;i++)
	{
		printf("%s \n",hospitales[i].nombre);

		for(int j = 0; j<tamanioMedicos;j++)
		{
			if(medicos[j].idHospital == hospitales[i].idHospital)
			{
				for(int l = 0; l<tamanio ;l++)
				{
					if(medicos[j].idMedico == consultas[l].idMedico)
					{
						printf("%20s %4d/%d/%d %4s\n",consultas[l].nombrePaciente,consultas[l].fechaDeAtencion.dia,consultas[l].fechaDeAtencion.mes,consultas[l].fechaDeAtencion.anio,consultas[l].diagnostico.descripcion);
					}
				}
			}
		}
	}
}
